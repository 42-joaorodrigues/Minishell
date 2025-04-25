/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:16:02 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/23 18:16:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/test.h"
#include "../../include/token.h"
#include "../../lib/include/jal_error.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

#include "expand.h"

static int	ft_execute_line(const char *line, char **envp)
{
	t_list	*token_list;

	(void)envp;
	token_list = ft_token_list(line);
	if (!token_list)
		return (*ft_exit_code());
	test_print_tokens(token_list);
	if (ft_expand(token_list, (const char **)envp) != 0)
		return (*ft_exit_code());
	test_print_tokens(token_list);
	ft_lstclear(&token_list, ft_free_token);
	return (0);
}

int	ft_read_input(char **envp)
{
	char *line;

	while (1)
	{
		line = readline(PROMPT);
		if (!line)
			break ;
		if (*line)
		{
			add_history(line);
			if (ft_execute_line(line, envp) != 0 && *ft_exit_code() != E_QUOTES)
				return (*ft_exit_code());
		}
		free(line);
	}
	rl_clear_history();
	return (0);
}