/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:29:22 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 13:29:24 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/* Função que tokeniza a linha de comando */
t_token	*tokenize_line(char *line);

/* Função que constrói a estrutura de comandos a partir dos tokens */
int		build_commands(t_shell *shell, t_token *tokens);

/* Função para liberar a memória alocada para os tokens */
void	free_tokens(t_token *tokens);

/* Função bônus para processar operadores lógicos e agrupamentos */
int		parse_bonus_logic(t_token **tokens, t_command **cmd_tree);

#endif
