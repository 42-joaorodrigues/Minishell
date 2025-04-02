/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:28:09 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 08:59:58 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static char	ft_quote_type(t_token_type token_type)
{
	if (token_type == TOKEN_SQUOTE)
		return ('\'');
	if (token_type == TOKEN_DQUOTE)
		return ('\"');
	return ('\0');
}

int	ft_process_quotes(t_token *token)
{
	char	*processed;
	char	*unquoted;

	if (token->type == TOKEN_WORD)
	{
		processed = ft_expand_str(token->value);
		free(token->value);
		token->value = processed;
		return (SUCCESS);
	}
	if (token->type == TOKEN_DQUOTE)
	{
		processed = ft_expand_str(token->value);
		unquoted = ft_remove_quotes(processed, ft_quote_type(token->type));
		free(processed);
	}
	else
		unquoted = ft_remove_quotes(token->value, ft_quote_type(token->type));
	if (!unquoted)
		return (ERROR);
	free(token->value);
	token->value = unquoted;
	if (token->type == TOKEN_SQUOTE || token->type == TOKEN_DQUOTE)
		token->type = TOKEN_WORD;
	return (SUCCESS);
}
