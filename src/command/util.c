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
#include <stdlib.h>
#include <unistd.h>
#include "jal_error.h"
#include "jal_memory.h"

t_command	*ft_new_command(char *cmd, char **args, const int fd_in, const int fd_out)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	new->cmd = cmd;
	new->args = args;
	new->fd_in = fd_in;
	new->fd_out = fd_out;
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

void	ft_free_command(t_command *command)
{
	if (!command)
		return ;
	if (command->cmd)
		free(command->cmd);
	if (command->args)
		ft_free_matrix((void **)command->args);
	if (command->fd_in > 2)
		close(command->fd_in);
	if (command->fd_out > 2)
		close(command->fd_out);
	free(command);
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
