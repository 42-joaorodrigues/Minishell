/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:49:25 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/14 15:48:48 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "jal_error.h"
#include "jal_string.h"
#include <math.h>
#include <readline/readline.h>

t_token	*ft_expand(const t_token *token, const char **envp)
{
	t_token	*expand;
	t_token	*new;

	expand = NULL;
	while (token)
	{
		if (token->type == TOKEN_WORD)
			new = ft_new_token(ft_expand_str(token->value, envp));
		else
			new = ft_new_token(ft_strdup(token->value));
		if (!new)
			return (ft_token_clear(expand), NULL);
		if (!new->value[0])
			ft_token_free(new);
		else
			ft_token_add_back(&expand, new);
		token = token->next;
	}
	return (expand);
}
