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

int	ft_env(const t_command *cmd, t_env *env)
{
	if (cmd->args[1])
		return (ft_status("env: too many arguments", S_ENV_ARGS));
	ft_print_env_fd(env->array, cmd->fd_out);
	*ft_status_code() = 0;
	return (0);
}
