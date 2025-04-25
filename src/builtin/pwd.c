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
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_exec_pwd(t_prog *prog, const t_command *cmd)
{
	if (cmd->args[1])
		return (ft_print_error(prog, E_PWD_ARGS));
	ft_putendl_fd(getenv("PWD"), cmd->output_fd);
	return (SUCCESS);
}
