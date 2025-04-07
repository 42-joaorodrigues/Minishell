/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:04:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/19 14:05:02 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "token.h"
#include <stdio.h>

static char	*ft_token_type_str(const t_token_type token_type)
{
	if (token_type == TOKEN_WORD)
		return ("Word");
	if (token_type == TOKEN_PIPE)
		return ("Pipe");
	if (token_type == TOKEN_APPEND)
		return ("Append");
	if (token_type == TOKEN_HEREDOC)
		return ("Heredoc");
	if (token_type == TOKEN_REDIRECT_IN)
		return ("Redirect_in");
	if (token_type == TOKEN_REDIRECT_OUT)
		return ("Redirect_out");
	return ("Unknown");
}

void	test_print_tokens(t_list *token_list)
{
	t_list *tmp;
	t_token *token;

	tmp = token_list;
	printf("\n");
	printf("###Tokens###\n");
	while (tmp)
	{
		token = (t_token *)tmp->content;
		printf("type: %s, value: %s\n", ft_token_type_str(token->type),
			token->value);
		tmp = tmp->next;
	}
}