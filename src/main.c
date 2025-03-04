/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:25:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/26 15:25:37 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" // Inclui as definições e funções necessárias (headers serão implementados depois)
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	(void)argc;
	(void)argv;
	/* Inicializa a estrutura do shell, copiando o ambiente e configurando variáveis */
	if (init_shell(&shell, envp) != SUCCESS)
		return (EXIT_FAILURE);
	/* Configurar signal handlers (ctrl-C, ctrl-D, ctrl-\) */
	setup_signals();
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;  // ctrl-D para sair
		if (*line)
			add_history(line);
		/* Chama o parser que preenche a estrutura de comandos */
		if (parse_input(&shell, line) == SUCCESS)
		{
			/* Executa os comandos lidos */
			execute_commands(&shell);
			/* Libera recursos da estrutura de comandos para o próximo input */
			cleanup_shell(&shell);
		}
		free(line);
	}
	free_shell(&shell);
	return (EXIT_SUCCESS);
}
/*
--Explicação do Código
Inicialização do Shell:
A função init_shell (a ser implementada) deve copiar o ambiente (envp) e preparar as variáveis necessárias para o funcionamento do shell.

Signal Handlers:
A função setup_signals é chamada para configurar o tratamento dos sinais (como ctrl-C, ctrl-D e ctrl-\), evitando que o shell saia de forma inesperada.

Loop Principal:
Dentro do loop, usamos readline para exibir o prompt e ler o comando do usuário. Se a linha não estiver vazia, ela é adicionada ao histórico com add_history. Em seguida, o comando é passado para o parser (parse_input), que deve montar a estrutura dos comandos, e, se não houver erro, o executor (execute_commands) é chamado.

Liberação de Recursos:
Ao final de cada iteração, a linha lida e as estruturas temporárias são liberadas para evitar vazamentos de memória. Ao sair do loop (quando o usuário envia um EOF com ctrl-D), o shell é finalizado com free_shell.

Com esse arquivo main.c temos o ponto de entrada do nosso Minishell. Nos próximos passos, iremos criar os arquivos dos módulos (parser, executor, builtins, utils) e, por fim, os headers e o Makefile
*/
