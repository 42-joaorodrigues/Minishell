/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:40:55 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/07 19:40:58 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "jal_char.h"
#include "jal_error.h"
#include "jal_print.h"
#include "jal_string.h"
#include "status.h"

int	ft_valid_varname(const char *name)
{
	if (*name != '_' && !ft_isalpha(*name))
		return (0);
	while (*name)
	{
		if (*name != '_' && !ft_isalnum(*name))
			return (0);
		name++;
	}
	return (1);
}

static void	ft_export_args(const t_command *command, t_env *env)
{
	int		i;
	char	*arg;
	char	*sign;

	i = 0;
	while (command->args[++i])
	{
		arg = command->args[i];
		sign = ft_strchr(arg, '=');

		if (sign)
			*sign = '\0';
		if (!ft_valid_varname(arg))
			ft_error("export: not a valid variable name", 0);
		else if (sign)
		{
			ft_set_env(env, arg, sign + 1);
			*sign = '=';
		}
		else
			ft_set_env(env, arg, "");
	}
}

int	ft_export(const t_command *command, t_env *env)
{
	if (!command || !env)
		return (1);
	if (!command->args[1])
	{
		ft_print_env_fd(env->array, command->fd_out);
		return (0);
	}
	ft_export_args(command, env);
	*ft_status_code() = 0;
	return (0);
}
