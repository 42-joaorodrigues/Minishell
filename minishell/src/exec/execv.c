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

int	ft_execv(t_command *head, t_command *cmd, char **envp, int *pid_ref)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_status("error", "fork failed", S_FORK));
	if (pid == 0)
		ft_child(head, cmd, envp);
	else
		*pid_ref = pid;
	return (0);
}
