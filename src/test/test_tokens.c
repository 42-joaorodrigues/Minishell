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

void	test_print_tokens(t_list *token_list)
{
	t_list	*tmp;
	t_token	*token;
	char	*str_type;

	tmp = token_list;
	while (tmp)
	{
		token = (t_token *)tmp->content;
		str_type = NULL;
		if (token->type == TOKEN_WORD)
			str_type = "Word";
		else if (token->type == TOKEN_PIPE)
			str_type = "Pipe";
		else if (token->type == TOKEN_APPEND)
			str_type = "Append";
		else if (token->type == TOKEN_HEREDOC)
			str_type = "Heredoc";
		else if (token->type == TOKEN_REDIRECT_IN)
			str_type = "Redirect_in";
		else if (token->type == TOKEN_REDIRECT_OUT)
			str_type = "Redirect_out";
		ft_printf("Token: type = %s, value = '%s'\n", str_type, token->value);
		tmp = tmp->next;
	}
}