/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:11:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 10:15:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "jal_memory.h"
#include "jal_string.h"
#include "minishell.h"

static int		ft_count_command_args(t_list *token_list)
{
	int		count;

	count = 0;
	if (!token_list)
		return (count);
	while (token_list && ((t_token *)token_list->content)->type == TOKEN_WORD)
	{
		token_list = token_list->next;
		count++;
	}
	return (count);
}

static char	**ft_get_command_args(t_list **token_list)
{
	char	**args;
	int		i;

	if (!token_list || !*token_list)
		return (NULL);
	args = malloc((ft_count_command_args(*token_list) + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = -1;
	while (*token_list && ((t_token *)(*token_list)->content)->type == TOKEN_WORD)
	{
		args[++i] = ((t_token *)(*token_list)->content)->value;
		ft_lstdel_safely(token_list, *token_list, free);
	}
	args[++i] = NULL;
	return (args);
}

static char	**ft_get_command_fds(t_list **token_list)
{
	t_command	*command;
	t_token		*redirect;


	if (!token_list)
		return (NULL);
	command->input_fd = STDIN_FILENO;
	command->output_fd = STDOUT_FILENO;
	while (*token_list && ((t_token *)(*token_list)->content)->type != TOKEN_PIPE)
	{
		if (((t_token *)(*token_list)->content)->type > 3)
		{
			redirect = (t_token *)(*token_list)->next->content;
			if (redirect->type == TOKEN_REDIRECT_IN)
				command->input_fd = open(redirect->value, O_RDONLY);
			else if (redirect->type == TOKEN_REDIRECT_OUT)
				command->output_fd = open(redirect->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else if (redirect->type == TOKEN_APPEND)
				command->output_fd = open(redirect->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
			//heredoc
			*token_list = (*token_list)->next->next;
			continue;
		}
		*token_list = (*token_list)->next;
	}
	return (command);
}

int  ft_command_from_token(t_prog *prog)
{
    t_command   *command;
    char        **args;
	int			input_fd;
	int			output_fd;

	args = ft_get_command_args(&prog->token_list);
	if (!args)
		return (ERROR);
	input_fd = STDIN_FILENO;
	output_fd = STDOUT_FILENO;
	if (ft_get_command_fds(prog->token_list, &input_fd, &output_fd) != SUCCESS)
		return (ERROR);
    command = ft_new_command(ft_strdup(args[0]), args, input_fd, output_fd);
    if (!command)
    {
        ft_free_matrix((void **)args, 0);
        return (ERROR);
    }
	ft_lstadd_back(&prog->command_list, ft_lstnew(command));
    return (SUCCESS);
}
