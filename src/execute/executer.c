/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:37:46 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/26 15:37:48 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "minishell.h"
#include <sys/wait.h>

int	execute_commands(t_shell *shell)
{
	pid_t	pid;
	int		status;

	/* Se não houver comandos, retorna com sucesso */
	if (!shell->commands)
		return (SUCCESS);
	/* Se for um comando built-in, executa sem fork */
	if (is_builtin(shell->commands->cmd))
		return (execute_builtin(shell->commands, shell));
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (ERROR);
	}
	if (pid == 0)
	{
		/* Configurar redirecionamentos e pipes, se houver */
		if (setup_redirections(shell->commands) != SUCCESS)
			exit(EXIT_FAILURE);
		execve(shell->commands->path, shell->commands->args, shell->env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		shell->last_status = status;
	}
	return (SUCCESS);
}

int setup_redirections(t_command *cmd)
{
    /* Implementação ou stub temporário */
    (void)cmd;
    return (SUCCESS);
}
