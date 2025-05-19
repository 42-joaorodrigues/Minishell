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

static void	ft_export_args(const t_command *command, char ***envp)
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
			ft_status("export", "not a valid identifier", S_EXPORT_ARGS);
		else if (sign)
		{
			ft_set_env(envp, arg, sign + 1);
			*sign = '=';
		}
	}
}

int	ft_export(t_command *command, char ***envp)
{
	if (!command || !envp)
		return (1);
	if (!command->args[1])
	{
		ft_print_env_fd((const char **)*envp, command->fd_out);
		return (*ft_status_code());
	}
	ft_export_args(command, envp);
	if (*ft_status_code() != 0)
		return (command->exit = *ft_status_code(), *ft_status_code());
	command->exit = 0;
	return (0);
}
