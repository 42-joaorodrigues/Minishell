/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:49:18 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 20:49:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "status.h"
#include <sys/wait.h>
#include "exec_int.h"

int	ft_execv(t_command *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (ft_status("fork failed", S_FORK));
	if (pid == 0)
		ft_child(cmd, envp);
	else
	{
		if (cmd->fd_in != STDIN_FILENO)
			close(cmd->fd_in);
		if (cmd->fd_out != STDOUT_FILENO)
			close(cmd->fd_out);
		waitpid(pid, &status, 0);
		*ft_status_code() = WEXITSTATUS(status);
	}
	return (0);
}
