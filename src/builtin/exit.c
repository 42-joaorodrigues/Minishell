/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:03:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 20:03:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "jal_char.h"
#include "jal_memory.h"
#include "status.h"
#include <stdlib.h>

static int	ft_free_exit(t_command *cmd, char **envp, int code)
{
	ft_clear_command(cmd);
	ft_free_envp(envp);
	exit(code);
}

static int	ft_code(char *arg)
{
	int	nbr;
	int	i;

	if (!arg[0] && !ft_isdigit(arg[0]) && arg[0] != '-' && arg[0] != '+')
		return (-1);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (-1);
		i++;
	}
	nbr = atoi(arg);
	if (nbr < 0)
		nbr = 156;
	return (nbr);
}

int	ft_exit(t_command *cmd, char **envp)
{
	int	code;

	if (!cmd->args[1])
		ft_free_exit(cmd, envp, 0);
	code = ft_code(cmd->args[1]);
	if (code == -1)
		return (cmd->exit = S_EXIT_NUM, ft_status("exit",
				"numeric argument required", S_EXIT_NUM));
	if (cmd->args[2])
		return (cmd->exit = S_EXIT_ARGS, ft_status("exit", "too many arguments",
				S_EXIT_ARGS));
	ft_free_exit(cmd, envp, code);
	return (0);
}
