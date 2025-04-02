/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:25:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/31 16:53:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "minishell.h"
#include "util.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

#include "test.h"

static int	ft_read_input()
{
	char	*input;
	t_list	*token_list;
	t_list	*command_list;

	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			token_list = ft_parser(input);
			if (!token_list)
				return (ERROR);
			test_print_tokens(token_list);
			command_list = ft_commands_from_tokens(&token_list);
			if (!command_list)
				return (ERROR);
			test_print_commands(command_list);
		}
		free(input);
	}
	rl_clear_history();
	return (SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_prog	prog;

	(void)ac;
	(void)av;
	(void)envp;
	ft_init_prog(&prog);
	if (ft_read_input() == ERROR)
	{
		ft_lstclear(&prog.token_list, ft_free_token);
		return (ft_print_error(prog.exit_code));
	}
	ft_lstclear(&prog.token_list, ft_free_token);
	return (SUCCESS);
}
