/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:11:28 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/07 18:11:31 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include "command.h"
#include "jal_memory.h"
#include "jal_print.h"
#include "jal_string.h"
#include "token.h"

static int	ft_count_args(t_token *token)
{
	int	count;

	count = 0;
	if (!token)
		return (count);
	while (token && token->type == TOKEN_WORD)
	{
		token = token->next;
		count++;
	}
	return (count);
}

static char	**ft_command_args(t_token **token)
{
	char	**args;
	int		i;

	if (!token)
		return (NULL);
	args = malloc((ft_count_args(*token) + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = -1;
	while (*token && (*token)->type == TOKEN_WORD)
	{
		args[++i] = ft_strdup((*token)->value);
		if (!args[i])
			return (ft_free_partial_matrix((void **)args, i - 1), NULL);
		*token = (*token)->next;
	}
	args[++i] = NULL;
	return (args);
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

static void	ft_command_fds(t_token **token, int *fd_in, int *fd_out)
{
	t_token	*redirect;

	if (!token)
		return ;
	while (*token && (*token)->type != TOKEN_PIPE)
	{
		if ((*token)->type != TOKEN_WORD)
		{
			redirect = (*token)->next;
			if ((*token)->type == TOKEN_REDIRECT_IN)
				*fd_in = open(redirect->value, O_RDONLY);
			else if ((*token)->type == TOKEN_REDIRECT_OUT)
				*fd_out = open(redirect->value,
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else if ((*token)->type == TOKEN_APPEND)
				*fd_out = open(redirect->value,
						O_WRONLY | O_CREAT | O_APPEND, 0644);
			else if ((*token)->type == TOKEN_HEREDOC)
				*fd_in = ft_heredoc(redirect->value);
			*token = (*token)->next;
		}
		*token = (*token)->next;
	}
}

t_command	*ft_create_command(t_token **token)
{
	char		**args;
	char		*cmd;
	int			fd[2];

	if (!token)
		return (NULL);
	args = ft_command_args(token);
	if (!args)
		return (NULL);
	cmd = ft_strdup(args[0]);
	if (!cmd)
		return (ft_free_matrix((void **)args), NULL);
	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	ft_command_fds(token, &fd[0], &fd[1]);
	if (fd[0] == -1 || fd[1] == -1)
		return (ft_free_matrix((void **)args), free(cmd), NULL);
	return (ft_new_command(cmd, args, fd[0], fd[1]));
}
