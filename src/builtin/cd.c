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

void	ft_cd(const t_command *command, t_env *env)
{
	char	old_pwd[1024];
	char	new_pwd[1024];

	if (!getcwd(old_pwd, 1024))
		ft_error("failed to get cwd", E_GETCWD);
	if (!command->args[1])
		ft_error("no cd path", E_CD_NO_PATH);
	else if (chdir(command->args[1]) != 0)
		ft_error("invalid cd path", E_CD_INVALID_PATH);
	if (!getcwd(new_pwd, 1024))
		ft_error("failed to get cwd", E_GETCWD);
	ft_set_env(env, "OLDPWD", old_pwd);
	ft_set_env(env, "PWD", new_pwd);
}
