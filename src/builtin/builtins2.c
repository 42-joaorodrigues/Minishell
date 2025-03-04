/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:45 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 18:16:20 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

int builtin_export(char **args, t_shell *shell)
{
    (void)shell;
    /* Stub: apenas imprimir o que seria exportado */
    if (!args || !args[1])
    {
        printf("export: lista de variáveis\n");
        return (SUCCESS);
    }
    printf("Exportando: %s\n", args[1]);
    return (SUCCESS);
}

int builtin_unset(char **args, t_shell *shell)
{
    (void)shell;
    if (!args || !args[1])
    {
        fprintf(stderr, "unset: falta argumento\n");
        return (ERROR);
    }
    printf("Desconfigurando variável: %s\n", args[1]);
    return (SUCCESS);
}

int builtin_env(t_shell *shell)
{
    int i = 0;

    if (!shell->env)
        return (ERROR);
    while (shell->env[i])
    {
        printf("%s\n", shell->env[i]);
        i++;
    }
    return (SUCCESS);
}

int builtin_exit(char **args, t_shell *shell)
{
    (void)shell;
    (void)args;
    printf("Saindo do Minishell...\n");
    exit(0);
    return (SUCCESS); // nunca será alcançado
}
