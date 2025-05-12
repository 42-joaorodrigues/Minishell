/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:49:25 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/25 14:49:25 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

#include <math.h>

#include "env.h"
#include "jal_char.h"
#include "jal_conversion.h"
#include "jal_error.h"
#include "jal_string.h"

static int	ft_trim_quotes(char **str)
{
	char	*trimmed;

	trimmed = ft_strndup(*str + 1, ft_strlen(*str) - 2);
	if (!trimmed)
		return (ft_error("memory allocation failed", E_NOMEM));
	free(*str);
	*str = trimmed;
	return (0);
}

int ft_expand_token(t_token *token, const char **envp)
{
    char *expanded;

    if (!token || !envp)
        return (1);
    while (token)
    {
        if (token->type == TOKEN_SQUOTE || token->type == TOKEN_DQUOTE)
        {
            if (ft_trim_quotes(&token->value) != 0)
                return (*ft_exit_code());
        }
        if (token->type == TOKEN_DQUOTE || token->type == TOKEN_WORD)
        {
            expanded = ft_expand_str(token->value, envp);
            if (!expanded)
                return (*ft_exit_code());
            free(token->value);
            token->value = expanded;
        }
        if (token->type == TOKEN_SQUOTE || token->type == TOKEN_DQUOTE)
            token->type = TOKEN_WORD;
        token = token->next;
    }
    return (0);
}
 