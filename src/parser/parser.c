/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:04:02 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/19 16:04:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"
#include "minishell.h"
#include "test.h"
#include "util.h"

int	ft_check_quotes(const char *input)
{
	char	quote;
	int		i;

	i = 0;
	while (input[i])
	{
		if (ft_is_quote(input[i]))
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				i++;
			if (!input[i])
				return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_parser(t_prog *prog, const char *input)
{
	t_list	*current;

	if (ft_check_quotes(input) == ERROR)
	{
		ft_print_error(E_QUOTES);
		return (SUCCESS);
	}
	if (ft_strncmp(input, "token", 5) == SUCCESS)
	{
		test_tokens(input, &prog->token_list);
		return (SUCCESS);
	}
	if (ft_lexer(&prog->token_list, input) == ERROR)
		return (prog->exit_code = E_MEM_ALLOC, ERROR);
	current = prog->token_list;
	while (current)
	{
		if (ft_process_quotes(current->content, prog) == ERROR)
			return (prog->exit_code = E_MEM_ALLOC, ERROR);
		current = current->next;
	}
	return (SUCCESS);
}
