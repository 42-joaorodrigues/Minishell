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

t_command	*ft_init_command(void)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->cmd = NULL;
	command->args = NULL;
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
	if (current->input_fd > 2)
		close(current->input_fd);
	if (current->output_fd > 2)
		close(current->output_fd);
	free(current);
}
