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
#include "util.h"
#include "test.h"

int	ft_check_quotes(const char *input)
{
	char	quote;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
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
	if (ft_check_quotes(input) == ERROR)
	{
		ft_print_error(E_QUOTES);
		return (SUCCESS);
	}
	if (ft_lexer(&prog->token_list, input) == ERROR)
		return (prog->exit_code = E_MEM_ALLOC, ERROR);
	if (ft_strcmp(input, "tokens") == SUCCESS)
		test_print_tokens(prog->token_list);
	return (SUCCESS);
}
