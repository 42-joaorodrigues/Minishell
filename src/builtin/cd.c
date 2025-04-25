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
#include "util.h"
#include <unistd.h>

void	ft_exec_cd(t_prog *prog, const t_command *cd)
{
	char	old_pwd[1024];
	char	new_pwd[1024];

	if (!getcwd(old_pwd, 1024))
		ft_print_error(prog, E_GETCWD);
	if (!cd->args[1])
		ft_print_error(prog, E_CD_NO_PATH);
	else if (chdir(cd->args[1]) != 0)
		ft_print_error(prog, E_CD_INVALID_PATH);
	if (!getcwd(new_pwd, 1024))
		ft_print_error(prog, E_GETCWD);
}
