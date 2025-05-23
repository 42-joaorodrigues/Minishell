/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:23:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/13 09:24:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "exec_int.h"

void	ft_close_fd(t_command *cmd)
{
	if (cmd->fd_in > 2)
	{
		close(cmd->fd_in);
		cmd->fd_in = -1;
	}
	if (cmd->fd_out > 2)
	{
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
}
