/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:05:27 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/07 15:05:29 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "jal_print.h"
#include <stdlib.h>
#include "jal_error.h"
#include "minishell.h"

void	ft_pwd(const t_command *cmd, t_env *env)
{
	if (cmd->args[1])
		ft_error("too many arguments", E_PWD_ARGS);
	ft_putendl_fd((char *)ft_get_env((const char **)env->array, "PWD"), cmd->fd_out);
}
