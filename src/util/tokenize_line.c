/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:09:46 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 18:09:47 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <stdlib.h>

t_token *tokenize_line(char *line)
{
    (void)line;
    /* Stub: retornar NULL indica que não há tokens */
    return (NULL);
}

void free_tokens(t_token *tokens)
{
    t_token *tmp;

    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);  // supondo que 'value' foi alocado
        free(tmp);
    }
}

int build_commands(t_shell *shell, t_token *tokens)
{
    (void)tokens;
    /* Stub: apenas define a lista de comandos como NULL */
    shell->commands = NULL;
    return (SUCCESS);
}

