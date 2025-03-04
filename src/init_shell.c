/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:04:27 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 18:04:28 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_string.h"
#include <stdlib.h>

int init_shell(t_shell *shell, char **envp)
{
    int i;
    int count;

    if (!shell || !envp)
        return (ERROR);
    shell->commands = NULL;
    shell->last_status = 0;
    /* Conta quantas variáveis de ambiente */
    for (count = 0; envp[count]; count++)
        ;
    shell->env = malloc(sizeof(char *) * (count + 1));
    if (!shell->env)
        return (ERROR);
    i = 0;
    while (envp[i])
    {
        shell->env[i] = ft_strdup(envp[i]);  // use sua função ft_strdup da libft
        i++;
    }
    shell->env[i] = NULL;
    return (SUCCESS);
}

void free_shell(t_shell *shell)
{
    int i;

    if (!shell)
        return;
    if (shell->env)
    {
        i = 0;
        while (shell->env[i])
        {
            free(shell->env[i]);
            i++;
        }
        free(shell->env);
    }
    /* Se houver estruturas de comandos, você deve liberá-las aqui também */
    shell->commands = NULL;
}

void cleanup_shell(t_shell *shell)
{
    /* Aqui você deve liberar ou resetar a lista de comandos do shell.
       Por enquanto, vamos apenas definir o ponteiro para NULL. */
    shell->commands = NULL;
}
