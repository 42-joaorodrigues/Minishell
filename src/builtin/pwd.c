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
#include "jal_error.h"
#include "minishell.h"
#include "status.h"

int	ft_pwd(t_command *cmd, const char **envp)
{
	ft_putendl_fd((char *)ft_get_env(envp, "PWD"), cmd->fd_out);
	cmd->exit = 0;
	return (0);
}
