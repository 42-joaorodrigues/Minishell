/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:00:40 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 09:00:42 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "jal_error.h"
#include "jal_memory.h"
#include <stdlib.h>
#include <unistd.h>

t_command	*ft_new_command(char **args, int fd_in, int fd_out,
		const int exit_code)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	new->cmd = NULL;
	new->args = args;
	if (args)
		new->cmd = args[0];
	new->fd_in = fd_in;
	new->fd_out = fd_out;
	new->pid = 0;
	new->exit = exit_code;
	new->next = NULL;
	return (new);
}

void	ft_command_add_back(t_command **head, t_command *new)
{
	t_command	*current;

	if (!head || !new)
		return ;
	current = *head;
	if (current)
	{
		while (current && current->next)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}

void	ft_free_command(t_command *cmd)
{
	if (!cmd)
		return ;
	if (cmd->args)
		ft_free_matrix((void **)cmd->args);
	if (cmd->fd_in > 2)
	{
		close(cmd->fd_in);
		cmd->fd_in = -1;
	}
	if (cmd->fd_out > 2)
	{
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
	free(cmd);
}

void	ft_clear_command(t_command *head)
{
	t_command	*next;

	while (head)
	{
		next = head->next;
		ft_free_command(head);
		head = next;
	}
}
