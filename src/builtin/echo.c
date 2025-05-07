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

void	ft_echo(const t_command *command)
{
	int	i;
	int	line_jump;

	i = 1;
	line_jump = 1;
	while (!ft_strncmp(command->args[i], "-n", 2))
	{
		line_jump = 0;
		i++;
	}
	while (command->args[i])
	{
		ft_putstr_fd(command->args[i], command->fd_out);
		if (command->args[i + 1])
			ft_putstr_fd(" ", command->fd_out);
		i++;
	}
	if (line_jump)
		ft_putstr_fd("\n", command->fd_out);
}
