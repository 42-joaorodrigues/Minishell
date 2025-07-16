/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:05:57 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/15 16:06:01 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "jal_char.h"
#include "jal_conversion.h"
#include "jal_error.h"
#include "jal_string.h"
#include "status.h"

static char	*ft_special(const char *str, int *index)
{
	char	*result;
	int		i;

	result = NULL;
	i = *index;
	if (str[i] == ' ' || str[i] == '\0' || str[i] == '\"')
		result = ft_strdup("$");
	else if (str[i] == '?' || str[i] == '$')
	{
		if (str[i] == '?')
			result = ft_itoa(*ft_status_code());
		else if (str[i] == '$')
			result = ft_strdup("");
		i++;
	}
	*index = i;
	if (!result)
		ft_error("memory allocation failed", E_NOMEM);
	return (result);
}

static char	*ft_env(const char *str, int *index, const char **envp)
{
	int		i;
	char	*to_expand;
	char	*expanded;
	char	*result;

	expanded = NULL;
	i = 0;
	while (ft_isalnum(str[*index + i]) || str[*index + i] == '_')
		i++;
	to_expand = ft_strndup(str + *index, i);
	if (!to_expand)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	expanded = (char *)ft_get_env(envp, to_expand);
	free(to_expand);
	if (expanded)
		result = ft_strdup(expanded);
	else
		result = ft_strdup("");
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	*index += i;
	return (result);
}

static char	*ft_text(const char *str, int *index, const char *delimiter)
{
	char	*result;
	int		i;

	i = *index;
	while (str[i] && !ft_strchr(delimiter, str[i]))
		i++;
	result = ft_strndup(str + *index, i - *index);
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	*index = i;
	return (result);
}

char	*ft_expand_chunk(const char *str, int *index, const char *delimiter,
		const char **envp)
{
	char	*result;
	int		i;

	i = *index;
	if (str[i] == '$')
	{
		i++;
		*index = i;
		if (str[i] == ' ' || str[i] == '\0' || str[i] == '\"' || str[i] == '?'
			|| str[i] == '$')
			result = ft_special(str, index);
		else
			result = ft_env(str, index, envp);
	}
	else
		result = ft_text(str, index, delimiter);
	return (result);
}
