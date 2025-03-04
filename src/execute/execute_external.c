/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:12:13 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 18:12:19 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int execute_external(t_command *cmd, t_shell *shell)
{
    pid_t pid;
    int status;

    (void)shell;
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return (ERROR);
    }
    if (pid == 0)
    {
        execve(cmd->path, cmd->args, shell->env);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (status);
}
