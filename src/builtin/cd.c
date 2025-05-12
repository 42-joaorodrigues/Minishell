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
#include <unistd.h>

#include "jal_error.h"
#include "minishell.h"
#include "status.h"

int	ft_cd(const t_command *command, t_env *env)
{
	char	old_pwd[1024];
	char	new_pwd[1024];

	if (!getcwd(old_pwd, 1024))
		return (ft_status("cd: failed to get cwd", S_GETCWD));
	if (!command->args[1])
		return (ft_status("cd: no cd path", S_CD_NO_PATH));
	if (chdir(command->args[1]) != 0)
		return (ft_status("cd: invalid cd path", S_CD_INVALID_PATH));
	if (!getcwd(new_pwd, 1024))
		return (ft_status("cd: failed to get cwd", S_GETCWD));
	ft_set_env(env, "OLDPWD", old_pwd);
	ft_set_env(env, "PWD", new_pwd);
	*ft_status_code() = 0;
	return (0);
}
