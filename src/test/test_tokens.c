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

#include "jal_colour.h"

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
	if (token_type == TOKEN_SQUOTE)
		return ("Single_quote");
	if (token_type == TOKEN_DQUOTE)
		return ("Double_quote");
	return ("Unknown");
}

void	test_print_tokens(t_token *token)
{
	printf(GREEN "###Tokens###\n" RESET);
	while (token)
	{
		printf(YELLOW "type:" RESET " %-13s" YELLOW "value:" RESET " %s\n", ft_token_type_str(token->type),
			token->value);
		token = token->next;
	}
	printf(GREEN "############" RESET "\n");
}