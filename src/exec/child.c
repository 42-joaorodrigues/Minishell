
#include <stdio.h>
#include <unistd.h>
#include "command.h"
#include "exec_int.h"
#include "jal_error.h"
#include "jal_memory.h"
#include "status.h"

static void	ft_exit_child(t_command *cmd, char **envp, int exit_code)
{
	ft_clear_command(cmd);
	ft_free_matrix((void **)envp);
	exit(exit_code);
}

static void ft_fd(t_command *cmd)
{
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
}

void	ft_child(t_command *cmd, char **envp)
{
	char *path;

	ft_fd(cmd);
	path = ft_path(cmd->cmd, envp);
	if (!path)
		ft_exit_child(cmd, envp,
			ft_error("memory allocation failed", E_NOMEM));
	if (!path[0])
	{
		free(path);
		ft_exit_child(cmd, envp,
					ft_status("command not found", S_CMD_NOT_FOUND));
	}
	execv(path, cmd->args);
	perror("execv failed");
	free(path);
	ft_exit_child(cmd, envp, 0);
}