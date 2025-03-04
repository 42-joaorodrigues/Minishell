/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:33:50 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 12:33:51 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "util.h"

/*
 *Lembre-se de que esse código é um esqueleto para ser adaptado conforme a estrutura dos seus tokens e comandos:
 * Função: parse_bonus_logic
 * --------------------------
 * Processa os tokens para tratar operadores lógicos (&&, ||) e agrupamentos
 * com parênteses, construindo uma árvore de comandos que respeita a precedência.
 *
 * Parâmetros:
 *   tokens: Ponteiro para a lista de tokens a ser processada.
 *   cmd_tree: Ponteiro para a árvore de comandos resultante.
 *
 * Retorna:
 *   SUCCESS se a análise for bem-sucedida, ou ERROR em caso de erro.
 */
int	parse_bonus_logic(t_token **tokens, t_command **cmd_tree)
{
	if (!tokens || !*tokens)
		return (SUCCESS);
	while (*tokens)
	{
		if ((*tokens)->type == TOKEN_PAREN_OPEN)
		{
			*tokens = (*tokens)->next; /* Pula o '(' */
			if (parse_bonus_logic(tokens, cmd_tree) == ERROR)
				return (ERROR);
			if (!*tokens || (*tokens)->type != TOKEN_PAREN_CLOSE)
				return (ft_print_error(E_PARENTHESES));
		}
		else if ((*tokens)->type == TOKEN_LOGIC)
		{
			/* 
			 * Aqui você deve criar um nó na árvore para o operador lógico 
			 * (&& ou ||) e combinar os comandos à esquerda e direita,
			 * respeitando a precedência.
			 */
		}
		else
		{
			/* Processa token de comando normal (pode chamar build_commands, por exemplo) */
		}
		*tokens = (*tokens)->next;
	}
	return (SUCCESS);
}
