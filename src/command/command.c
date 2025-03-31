/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:11:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/29 14:11:24 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "jal_memory.h"
#include "jal_string.h"
#include "minishell.h"

t_command	*ft_new_command(char *cmd, char **args)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->cmd = cmd;
	command->args = args;
	command->input_fd = STDIN_FILENO;
	command->output_fd = STDOUT_FILENO;
	return (command);
}

void	ft_free_command(void *command)
{
	t_command	*current;
	int			i;

	current = (t_command *)command;
	if (!current)
		return ;
	if (current->cmd)
		free(current->cmd);
	i = -1;
	if (current->args)
	{
		while (current->args[++i])
			free(current->args[i]);
		free(current->args);
	}
	free(current);
}

t_list  *ft_command_from_token(t_prog *prog)
{
    t_command   *command;
    t_list      *current;
    t_list      *next;
    t_token     *token;
    char        **args;
    int         arg_count;

    current = prog->token_list;
    if (!current)
        return (NULL);

    arg_count = 0;
    next = current;
    while (next && ((t_token *)next->content)->type != TOKEN_PIPE)
    {
        arg_count++;
        next = next->next;
    }

    // Allocate args array
    args = malloc(sizeof(char *) * (arg_count + 1));
    if (!args)
        return (NULL);

    // Fill args array
    arg_count = 0;
    while (current && ((t_token *)current->content)->type != TOKEN_PIPE)
    {
        token = (t_token *)current->content;
        args[arg_count++] = ft_strdup(token->value);
    	next = current->next;
    	ft_lstdelone(current, ft_free_token);
        current = next;
    }
	prog->token_list = current;
    args[arg_count] = NULL;

    // Create new command
    command = ft_new_command(ft_strdup(args[0]), args);
    if (!command)
    {
        ft_free_matrix((void **)args, 0);
        return (NULL);
    }

    return (ft_lstnew(command));
}
