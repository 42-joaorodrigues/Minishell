/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:11:28 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/19 07:31:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec/exec_int.h"
#include "command.h"
#include "jal_memory.h"
#include "jal_print.h"
#include "jal_string.h"
#include "status.h"
#include "token.h"
#include <errno.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_count_args(t_token *token)
{
	int	count;

	count = 0;
	if (!token)
		return (count);
	while (token && token->type != TOKEN_PIPE)
	{
		if (token->type != TOKEN_WORD)
			token = token->next;
		else
			count++;
		token = token->next;
	}
	return (count);
}

static int	ft_heredoc(const char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
		return (-1);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = readline("");
	while (line && ft_strcmp(line, delimiter) != 0)
	{
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = readline("");
	}
	if (line)
		free(line);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

static int	ft_redirection(int *fd_in, int *fd_out, t_token_type type,
		char *value)
{
	if (type == TOKEN_REDIRECT_IN)
		*fd_in = open(value, O_RDONLY);
	else if (type == TOKEN_REDIRECT_OUT)
		*fd_out = open(value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == TOKEN_APPEND)
		*fd_out = open(value, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (type == TOKEN_HEREDOC)
		*fd_in = ft_heredoc(value);
	if (*fd_in == -1 || *fd_out == -1)
	{
		ft_status("redirection", strerror(errno), 1);
		return (1);
	}
	return (0);
}

static int	ft_fill_command(t_token **token, char **args, int *fd_in,
		int *fd_out)
{
	int	i;

	i = 0;
	while (*token && (*token)->type != TOKEN_PIPE)
	{
		if ((*token)->type != TOKEN_WORD)
		{
			if (ft_redirection(fd_in, fd_out, (*token)->type,
					(*token)->next->value))
			{
				while (*token && (*token)->type != TOKEN_PIPE)
					*token = (*token)->next;
				args[i] = NULL;
				return (1);
			}
			*token = (*token)->next;
		}
		else
			args[i++] = ft_strdup((*token)->value);
		*token = (*token)->next;
	}
	args[i] = NULL;
	return (0);
}

t_command	*ft_create_command(t_token **token)
{
	char	**args;
	int		fd[2];
	int		exit_code;

	args = malloc((ft_count_args(*token) + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	exit_code = 0;
	if (ft_fill_command(token, args, &fd[0], &fd[1]))
	{
		ft_free_matrix((void **)args);
		args = NULL;
		exit_code = 1;
	}
	return (ft_new_command(args, fd[0], fd[1], exit_code));
}
