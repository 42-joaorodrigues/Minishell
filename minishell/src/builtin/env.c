/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:58:02 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 19:58:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "status.h"

int	ft_env(t_command *cmd, const char **envp)
{
	if (cmd->args[1])
		return (cmd->exit = S_ENV_ARGS, ft_status("env", "too many arguments",
				S_ENV_ARGS));
	ft_print_env_fd(envp, cmd->fd_out);
	cmd->exit = 0;
	return (0);
}
