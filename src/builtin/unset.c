/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:48:22 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 19:50:28 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "status.h"

int	ft_unset(const t_command *cmd, t_env *env)
{
	int	i;

	if (!cmd->args[1])
		return (ft_status("unset: not enough arguments", S_UNSET_ARGS));
	i = 1;
	while (cmd->args[i])
		ft_unset_env(env, cmd->args[i++]);
	*ft_status_code() = 0;
	return (0);
}
