/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:52:41 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/04 15:18:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "builtin.h"

void	ft_exec_command(t_prog *prog, t_list **command_list)
{
	t_list		*current;
	t_command	*command;

	(void)prog;
	current = *command_list;
	while (current)
	{
		command = (t_command *)current->content;
		if (ft_is_builtin(command->cmd))
			ft_exec_builtin(prog, command);
		current = current->next;
	}
}