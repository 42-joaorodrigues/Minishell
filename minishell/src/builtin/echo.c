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
#include "jal_error.h"
#include "jal_print.h"
#include "jal_string.h"
#include "status.h"

static int	ft_n_flag(const char *arg)
{
	int	i;

	if (ft_strncmp(arg, "-n", 2) != 0)
		return (0);
	i = 2;
	while (arg[i] == 'n')
		i++;
	return (arg[i] == '\0');
}

int	ft_echo(t_command *command)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = 1;
	while (command->args[i] && ft_n_flag(command->args[i]))
	{
		new_line = 0;
		i++;
	}
	while (command->args[i])
	{
		ft_putstr_fd(command->args[i], command->fd_out);
		if (command->args[i + 1])
			ft_putstr_fd(" ", command->fd_out);
		i++;
	}
	if (new_line)
		ft_putstr_fd("\n", command->fd_out);
	command->exit = 0;
	return (0);
}
