/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:00:01 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/17 17:00:01 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_error.h"
#include "jal_string.h"
#include "token.h"
#include <stdlib.h>

t_token_type	ft_token_type(const char *value)
{
	if (value[0] == '|' && value[1] == '\0')
		return (TOKEN_PIPE);
	if (value[0] == '<' && value[1] == '\0')
		return (TOKEN_REDIRECT_IN);
	if (value[0] == '>' && value[1] == '\0')
		return (TOKEN_REDIRECT_OUT);
	if (ft_strncmp(value, ">>", 2) == 0 && value[2] == '\0')
		return (TOKEN_APPEND);
	if (ft_strncmp(value, "<<", 2) == 0 && value[2] == '\0')
		return (TOKEN_HEREDOC);
	if (value[0] == '\'' && value[ft_strlen(value) - 1] == '\'')
		return (TOKEN_SQUOTE);
	if (value[0] == '\"' && value[ft_strlen(value) - 1] == '\"')
		return (TOKEN_DQUOTE);
	return (TOKEN_WORD);
}

t_list	*ft_lstnew_token(const t_token_type type, char *value)
{
	t_list	*node;
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	node = ft_lstnew(token);
	if (!node)
	{
		free(token);
		ft_error("memory allocation failed", E_NOMEM);
		return (NULL);
	}
	return (node);
}

void	ft_free_token(void *token)
{
	t_token	*curr;

	curr = (t_token *)token;
	if (!curr)
		return ;
	if (curr->value)
		free(curr->value);
	free(curr);
}
