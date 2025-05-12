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

#include <stdlib.h>
#include "builtin.h"
#include "jal_char.h"
#include "jal_memory.h"
#include "status.h"

static int	ft_free_exit(t_command *cmd, t_env *env, int code)
{
	ft_clear_command(cmd);
	ft_free_matrix((void **)env->array);
	exit (code);
}

static int	ft_code(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (-1);
		i++;
	}
	return (atoi(arg));
}

int	ft_exit(t_command *cmd, t_env *env)
{
	int	code;

	if (!cmd->args[1])
		ft_free_exit(cmd, env, 0);
	code = ft_code(cmd->args[1]);
	if (code == -1)
		return (ft_status("exit: numeric argument required", S_EXIT_NUM));
	if (cmd->args[2])
		return (ft_status("exit: too many arguments", S_EXIT_ARGS));
	ft_free_exit(cmd, env, code);
	return (0);
}
