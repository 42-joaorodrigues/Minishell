/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:32:12 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 13:32:14 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

/* Função para executar os comandos lidos e construídos pelo parser */
int		execute_commands(t_shell *shell);

/* Função para executar comandos externos com fork e execve */
int		execute_external(t_command *cmd, t_shell *shell);

/* Função bônus: executa a árvore de comandos que pode conter operadores lógicos (&&, ||)
   e realiza a expansão de wildcards */
int		executer_bonus(t_command *cmd_tree, t_shell *shell);

int setup_redirections(t_command *cmd);

#endif

