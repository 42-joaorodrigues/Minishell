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

t_list	*ft_parser(const char *input)
{
	t_list	*token_list;
	t_list	*current;

	token_list = NULL;
	if (ft_check_quotes(input) == ERROR)
		return (NULL);
	if (ft_lexer(&token_list, input) == ERROR)
		return (NULL);
	current = token_list;
	while (current)
	{
		if (ft_process_quotes(current->content) == ERROR)
			return (NULL);
		current = current->next;
	}
	return (token_list);
}
