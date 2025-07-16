/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:52:41 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/17 19:01:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "command.h"
#include "exec.h"
#include "exec_int.h"
#include "status.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

static void	ft_wait_children(t_command *cmd)
{
	int	status;

	while (cmd)
	{
		if (cmd->pid)
		{
			waitpid(cmd->pid, &status, 0);
			if (!cmd->exit)
				*ft_status_code() = WEXITSTATUS(status);
			else
				*ft_status_code() = cmd->exit;
		}
		else
			*ft_status_code() = cmd->exit;
		cmd = cmd->next;
	}
}

void	ft_exec(t_command *head, char ***envp)
{
	t_command	*cmd;

	if (!head || !envp)
		return ;
	cmd = head;
	while (cmd)
	{
		if (cmd->cmd && cmd->exit == 0)
		{
			if (ft_is_builtin(cmd->cmd))
				ft_exec_builtin(cmd, envp);
			else if (cmd->cmd)
				ft_execv(head, cmd, *envp, &cmd->pid);
		}
		ft_close_fd(cmd);
		cmd = cmd->next;
	}
	ft_wait_children(head);
}
