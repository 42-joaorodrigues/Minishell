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

#include "../../include/builtin.h"
#include "../../include/command.h"

void	ft_exec(t_command *command, t_env *env)
{
	if (!command || !env)
		return ;
	while (command)
	{
		if (ft_is_builtin(command->cmd))
			ft_exec_builtin(command, env);
		command = command->next;
	}
}