/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:56:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/02 08:56:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"

void	test_print_commands(const t_list *command_list)
{
	t_command	*command;
	int			j;

	j = 0;
	while (command_list)
	{
		command = (t_command *)command_list->content;
		printf("\n");
		printf("###Command[%d]###\n", j++);
		printf("cmd: %s\n", command->cmd);
		for (int i = 0; command->args[i]; i++)
			printf("args[i]: %s\n", command->args[i]);
		printf("input_fd: %d\n", command->input_fd);
		printf("output_fd: %d\n", command->output_fd);
		command_list = command_list->next;
	}
}

