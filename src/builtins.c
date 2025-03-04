/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_string.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/*
 * Função: is_builtin
 * --------------------
 * Verifica se o comando informado é um builtin.
 *
 * Retorna: 1 se for builtin, 0 caso contrário.
 * xd
 */
int	is_builtin(const char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

/*
 * Função: execute_builtin
 * --------------------
 * Executa o builtin correspondente ao comando.
 *
 * Retorna: SUCCESS se executado corretamente, ou ERROR em caso de falha.
 */
int	execute_builtin(t_command *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		return (builtin_echo(cmd->args));
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		return (builtin_cd(cmd->args, shell));
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		return (builtin_export(cmd->args, shell));
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		return (builtin_unset(cmd->args, shell));
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		return (builtin_env(shell));
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		return (builtin_exit(cmd->args, shell));
	return (ERROR);
}

int builtin_echo(char **args)
{
    int i = 1;
    while (args && args[i])
    {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
        i++;
    }
    printf("\n");
    return (SUCCESS);
}

int builtin_cd(char **args, t_shell *shell)
{
    (void)shell;
    if (!args || !args[1])
    {
        fprintf(stderr, "cd: falta argumento\n");
        return (ERROR);
    }
    if (chdir(args[1]) != 0)
    {
        perror("cd");
        return (ERROR);
    }
    return (SUCCESS);
}

int builtin_pwd(void)
{
    char cwd[PATH_MAX];

    if (!getcwd(cwd, sizeof(cwd)))
    {
        perror("pwd");
        return (ERROR);
    }
    printf("%s\n", cwd);
    return (SUCCESS);
}


