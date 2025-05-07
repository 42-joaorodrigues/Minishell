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

#include "command.h"
#include "jal_string.h"
#include "token.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command_int.h"

t_command	*ft_command(t_token *token)
{
	t_token		*current;
	t_command	*head;
	t_command	*new;
	int			prev_pipe_fd[2];
	int			pipe_flag;

	if (!token)
		return (NULL);
	head = NULL;
	pipe_flag = 0;
	current = token;
	while (current)
	{
		new = ft_create_command(&current);
		if (!new)
			return (ft_clear_command(head), NULL);
		if (pipe_flag && new->fd_in == STDIN_FILENO)
			new->fd_in = prev_pipe_fd[0];
		else if (pipe_flag)
			close(prev_pipe_fd[0]);
		if (current && current->type == TOKEN_PIPE)
		{
			if (pipe(prev_pipe_fd) < 0)
				return (ft_free_command(new), ft_clear_command(head), NULL);
			if (new->fd_out == STDOUT_FILENO)
				new->fd_out = prev_pipe_fd[1];
			else
				close(prev_pipe_fd[1]);
			pipe_flag = 1;
			current = current->next;
		}
		else
			pipe_flag = 0;
		ft_command_add_back(&head, new);
	}
	return (head);
}
