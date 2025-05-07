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

#include "env.h"
#include "jal_char.h"
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

static char *ft_process_dollar(char *str, int *i, const char **envp, char *expanded)
{
    int j = 0;
    char *to_expand;
    const char *exp_value;

    (*i)++;
    while (ft_isalnum(str[*i + j]) || str[*i + j] == '_')
        j++;
    to_expand = ft_strndup(str + *i, j);
    if (!to_expand)
        return (free(expanded), ft_error("memory allocation failed", E_NOMEM), NULL);
    exp_value = ft_get_env(envp, to_expand);
    if (exp_value)
        expanded = ft_strjoin_free(expanded, (char *)exp_value, 1);
    free(to_expand);
    *i += j;
    return expanded;
}

static char *ft_process_text(char *str, int *i, char *expanded)
{
    int j = 0;
    char *chunk;

    while (str[*i + j] && str[*i + j] != '$')
        j++;
    chunk = ft_strndup(str + *i, j);
    if (!chunk)
        return (free(expanded), ft_error("memory allocation failed", E_NOMEM), NULL);
    expanded = ft_strjoin_free(expanded, chunk, 3);
    *i += j;
    return expanded;
}

static char *ft_expand_value(char *str, const char **envp)
{
    int i = 0;
    char *expanded;

    expanded = ft_strdup("");
    if (!expanded)
        return (ft_error("memory allocation failed", E_NOMEM), NULL);
    while (str[i])
    {
        if (str[i] == '$')
            expanded = ft_process_dollar(str, &i, envp, expanded);
        else
            expanded = ft_process_text(str, &i, expanded);
        if (!expanded)
            return (NULL);
    }
    return (expanded);
}

int ft_expand(t_token *token, const char **envp)
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
            token->type = TOKEN_WORD;
        }
        if (token->type == TOKEN_DQUOTE || token->type == TOKEN_WORD)
        {
            expanded = ft_expand_value(token->value, envp);
            if (!expanded)
                return (*ft_exit_code());
            free(token->value);
            token->value = expanded;
        }
        token = token->next;
    }
    return (0);
}
 