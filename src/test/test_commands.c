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

#include "command.h"
#include "test.h"
#include <stdio.h>

#include "jal_colour.h"

void	test_print_commands(t_command *command)
{
	int			j;

	j = 0;
	while (command)
	{
		printf("\n");
		printf(GREEN "###Command[%d]###\n" RESET, j++);
		printf(YELLOW "cmd:" RESET " %s\n", command->cmd);
		for (int i = 0; command->args[i]; i++)
			printf(YELLOW "args[%d]:" RESET " %s\n", i, command->args[i]);
		printf(YELLOW "input_fd:" RESET " %d\n", command->fd_in);
		printf(YELLOW "output_fd:" RESET " %d\n", command->fd_out);
		printf(GREEN "###############" RESET "\n");
		command = command->next;
	}
}
