/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:00:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/19 14:12:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "exec_int.h"
#include "jal_error.h"
#include "jal_memory.h"
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_exit_child(t_command *head, char **envp, char *path,
		int exit_code)
{
	ft_clear_command(head);
	ft_free_matrix((void **)envp);
	if (path)
		free(path);
	exit(exit_code);
}

static void	ft_fd(t_command *head, t_command *cmd)
{
	while (head)
	{
		if (head != cmd)
			ft_close_fd(head);
		head = head->next;
	}
	if (cmd->fd_in != -1 && cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != -1 && cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
}

void	ft_child(t_command *head, t_command *cmd, char **envp)
{
	char	*path;

	ft_fd(head, cmd);
	path = ft_path(cmd->cmd, envp);
	if (!path)
		ft_exit_child(head, envp, path, ft_error("memory allocation failed",
				E_NOMEM));
	if (execve(path, cmd->args, envp) != 0)
	{
		perror("execv failed");
		ft_exit_child(cmd, envp, path, 127);
	}
	ft_exit_child(cmd, envp, path, 0);
}
