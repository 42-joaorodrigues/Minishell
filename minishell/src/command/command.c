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
#include "command_int.h"
#include "jal_error.h"
#include "jal_string.h"
#include "test.h"
#include "token.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_handle_command(t_token **token, t_command **head,
		t_command *prev, t_command **new)
{
	int	pipe_fd[2];

	*new = ft_create_command(token);
	if (!*new)
		return (1);
	ft_command_add_back(head, *new);
	if (prev)
	{
		if (pipe(pipe_fd) == -1)
			return (ft_error("pipe failed", 1));
		if (prev->fd_out == STDOUT_FILENO)
			prev->fd_out = pipe_fd[1];
		if ((*new)->fd_in == STDIN_FILENO)
			(*new)->fd_in = pipe_fd[0];
	}
	return (0);
}

t_command	*ft_command(t_token *token)
{
	t_command	*head;
	t_command	*prev;
	t_command	*new;

	head = NULL;
	prev = NULL;
	new = NULL;
	while (token)
	{
		if (token->type != TOKEN_PIPE)
			if (ft_handle_command(&token, &head, prev, &new))
				return (ft_clear_command(head), NULL);
		prev = new;
		if (token && token->type == TOKEN_PIPE)
			token = token->next;
	}
	return (head);
}
