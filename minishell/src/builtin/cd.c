/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:39:34 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/07 14:39:38 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "jal_error.h"
#include "minishell.h"
#include "status.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	ft_cd(t_command *command, char ***envp)
{
	char	old_pwd[1024];
	char	new_pwd[1024];

	if (!command->args[1])
		return (command->exit = S_CD_NO_PATH, ft_status("cd", "no cd path",
				S_CD_NO_PATH));
	if (command->args[2])
		return (command->exit = S_CD_ARGS, ft_status("cd", "too many arguments",
				S_CD_ARGS));
	if (!getcwd(old_pwd, 1024))
		return (command->exit = 1, ft_status("cd", strerror(errno), 1));
	if (chdir(command->args[1]) != 0)
		return (command->exit = 1, ft_status("cd", strerror(errno), 1));
	if (!getcwd(new_pwd, 1024))
		return (command->exit = 1, ft_status("cd", strerror(errno), 1));
	ft_set_env(envp, "OLDPWD", old_pwd);
	ft_set_env(envp, "PWD", new_pwd);
	command->exit = 0;
	return (0);
}
