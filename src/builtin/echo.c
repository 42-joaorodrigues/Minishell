/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:19:59 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/04 15:28:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "jal_print.h"
#include "jal_string.h"

void	ft_exec_echo(const t_command *cmd)
{
	int	i;
	int	line_jump;

	i = 1;
	line_jump = 1;
	while (!ft_strncmp(cmd->args[i], "-n", 2))
	{
		line_jump = 0;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], cmd->output_fd);
		if (cmd->args[i + 1])
			ft_putstr_fd(" ", cmd->output_fd);
		i++;
	}
	if (line_jump)
		ft_putstr_fd("\n", cmd->output_fd);
}
