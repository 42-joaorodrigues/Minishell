/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:30:16 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 16:34:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "jal_char.h"
#include "jal_conversion.h"
#include "jal_error.h"
#include "jal_string.h"
#include "status.h"

static char *ft_special_case(char *
                             str, int *i)
{
    char    *chunk;

    chunk = NULL;
    if (str[*i] == ' ' || str[*i] == '\0')
        chunk = ft_strdup("$");
    else if (str[*i] == '?' || str[*i] == '$')
    {
        if (str[*i] == '?')
            chunk = ft_itoa(*ft_status_code());
        else if (str[*i] == '$')
            chunk = ft_strdup("");
        *i += 1;
    }
    if (!chunk)
        ft_error("memory allocation failed", E_NOMEM);
    return (chunk);
}

static char *ft_env_case(char *str, int *i, const char **envp)
{
    int     j;
    char    *to_expand;
    char    *env_value;
    char    *expanded;

    expanded = NULL;
    j = 0;
    while (ft_isalnum(str[*i + j]) || str[*i + j] == '_')
        j++;
    to_expand = ft_strndup(str + *i, j);
    if (!to_expand)
        return (ft_error("memory allocation failed", E_NOMEM), NULL);
    env_value = (char *)ft_get_env(envp, to_expand);
    free(to_expand);
    if (env_value)
        expanded = ft_strdup(env_value);
    else
        expanded = ft_strdup("");
    if (!expanded)
        return (ft_error("memory allocation failed", E_NOMEM), NULL);
    *i += j;
    return (expanded);
}

static char *ft_dollar_chunk(char *str, int *i, const char **envp)
{
    char *chunk;

    (*i)++;
    if (str[*i] == ' ' || str[*i] == '\0' || str[*i] == '?' || str[*i] == '$')
        chunk = ft_special_case(str, i);
    else
        chunk = ft_env_case(str, i, envp);
    return (chunk);
}

static char *ft_text_chunk(char *str, int *i)
{
    int j = 0;
    char *chunk;

    while (str[*i + j] && str[*i + j] != '$')
        j++;
    chunk = ft_strndup(str + *i, j);
    if (!chunk)
        return (ft_error("memory allocation failed", E_NOMEM), NULL);
    *i += j;
    return (chunk);
}

char *ft_expand_str(char *str, const char **envp)
{
    int     i;
    char    *expanded;
    char    *chunk;

    expanded = ft_strdup("");
    if (!expanded)
        return (ft_error("memory allocation failed", E_NOMEM), NULL);
    i = 0;
    while (str[i])
    {
        if (str[i] == '$')
            chunk = ft_dollar_chunk(str, &i, envp);
        else
            chunk = ft_text_chunk(str, &i);
        if (!chunk)
            return (free(expanded), NULL);
        expanded = ft_strjoin_free(expanded, chunk, 3);
        if (!expanded)
            return (ft_error("memory allocation failed", E_NOMEM), NULL);
    }
    return (expanded);
}
