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
#include "token.h"
#include "command.h"
#include "test.h"
#include "util.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

static int	ft_execute_line(t_prog *prog, char *line)
{
	t_list	*token_list;
	t_list	*command_list;

	if (ft_check_quotes(line) == ERROR)
		return (ft_print_error(prog, E_QUOTES), SUCCESS);
	token_list = ft_get_token_list(prog, line);
	if (!token_list)
		return (ft_print_error(prog, E_MEM_ALLOC));
	//test_print_tokens(token_list);
	command_list = ft_commands_from_tokens(&token_list);
	if (!command_list)
		return (ERROR);
	//test_print_commands(command_list);
	ft_exec_command(prog, &command_list);
	ft_lstclear(&command_list, ft_free_command);
	return (SUCCESS);
}

static int	ft_read_input(t_prog *prog)
{
	char	*line;

	while (1)
	{
		line = readline(PROMPT);
		if (!line)
			break ;
		if (*line)
		{
			add_history(line);
			if (ft_execute_line(prog, line) == ERROR)
				return (ERROR);
		}
		free(line);
	}
	rl_clear_history();
	return (SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_prog	prog;

	(void)ac;
	(void)av;
	prog.last_cmd_exit_code = 0;
	prog.exit_code = 0;
	prog.envp = envp;
	if (ft_read_input(&prog) == ERROR)
		return (prog.exit_code);
	return (SUCCESS);
}
