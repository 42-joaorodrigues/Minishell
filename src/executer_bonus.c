/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:38:18 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 12:38:19 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_string.h"

/*
 * Função: executor_bonus
 * -----------------------
 * Processa a árvore de comandos que pode conter operadores lógicos (&&, ||)
 * e expande wildcards antes de executar os comandos.
 *
 * Retorna: o status de execução do último comando ou ERROR em caso de falha.
 */
int	executor_bonus(t_command *cmd_tree, t_shell *shell)
{
	int	status;

	if (!cmd_tree)
		return (SUCCESS);
	/* Se o nó representa um operador lógico, processa recursivamente */
	if (cmd_tree->type == TOKEN_LOGIC)
	{
		status = executor_bonus(cmd_tree->left, shell);
		if ((ft_strcmp(cmd_tree->logic, "&&") == 0 && status != 0)
			|| (ft_strcmp(cmd_tree->logic, "||") == 0 && status == 0))
			return (status);
		return (executor_bonus(cmd_tree->right, shell));
	}
	/* Se o comando possui wildcards, expande-os */
	if (has_wildcard(cmd_tree->cmd))
		cmd_tree->args = expand_wildcards(cmd_tree->cmd);
	/* Executa o comando: se for built-in, executa diretamente; senão, externo */
	if (is_builtin(cmd_tree->cmd))
		status = execute_builtin(cmd_tree, shell);
	else
		status = execute_external(cmd_tree, shell);
	return (status);
}
