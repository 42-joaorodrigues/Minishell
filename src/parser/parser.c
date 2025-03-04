/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:29:15 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/26 15:29:17 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Função: parse_input
 * --------------------
 * Recebe a linha de comando e preenche a estrutura do shell com os comandos.
 * Realiza a tokenização (respeitando aspas, redirecionamentos, pipes, etc.)
 * e constrói uma lista de comandos para execução.
 *
 * Retorna: SUCCESS se a análise foi bem-sucedida, ou ERROR caso contrário.
 */
int	parse_input(t_shell *shell, char *line)
{
	t_token	*tokens;

	/* Tokeniza a linha de comando */
	tokens = tokenize_line(line);
	if (!tokens)
		return (ERROR);
	/* Constrói a estrutura de comandos a partir dos tokens */
	if (build_commands(shell, tokens) != SUCCESS)
	{
		free_tokens(tokens);
		return (ERROR);
	}
	free_tokens(tokens);
	return (SUCCESS);
}
