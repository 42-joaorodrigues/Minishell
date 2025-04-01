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

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

t_command	*ft_new_command(char *cmd, char **args, const int in_fd,
	const int out_fd)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->cmd = cmd;
	command->args = args;
	command->input_fd = in_fd;
	command->output_fd = out_fd;
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
