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

#include "jal_string.h"
#include "token.h"
#include <stdlib.h>

t_token_type	ft_get_token_type(char *s)
{
	if (s[0] == '|' && s[1] == '\0')
		return (TOKEN_PIPE);
	if (s[0] == '<' && s[1] == '\0')
		return (TOKEN_REDIRECT_IN);
	if (s[0] == '>' && s[1] == '\0')
		return (TOKEN_REDIRECT_OUT);
	if (ft_strncmp(s, ">>", 2) == 0)
		return (TOKEN_APPEND);
	if (ft_strncmp(s, "<<", 2) == 0)
		return (TOKEN_HEREDOC);
	return (TOKEN_WORD);
}

t_token	*ft_new_token(const t_token_type type, char *value)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->value = value;
	return (new);
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
