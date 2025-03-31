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

#include "minishell.h"
#include "util.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

static int	ft_read_input(t_prog *prog)
{
	char	*input;

	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			if (ft_parser(prog, input) == ERROR)
				return (ERROR);
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
	if (ft_read_input(&prog) == ERROR)
	{
		ft_lstclear(&prog.token_list, ft_free_token);
		return (ft_print_error(prog.exit_code));
	}
	ft_lstclear(&prog.token_list, ft_free_token);
	return (SUCCESS);
}
