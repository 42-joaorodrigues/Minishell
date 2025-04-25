/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:12:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/23 20:13:04 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/include/jal_error.h"
#include "../../lib/include/jal_string.h"
#include "token_int.h"

static char	*ft_trim_single_quotes(const char *str, int *i)
{
	char	*trimmed;
	int		trimmed_len;

	trimmed_len = 0;
	(*i)++;
	while (str[*i + trimmed_len] != '\'')
		trimmed_len++;
	trimmed = ft_strndup(&str[*i], trimmed_len++);
	if (!trimmed)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	*i += trimmed_len;
	return (trimmed);
}

static char	*ft_trim_and_expand(const char *str, int *i, char **envp)
{
	char	*trimmed;
	size_t	trimmed_len;
	char	*expanded;

	trimmed_len = 0;
	if (str[*i] == '\"')
	{
		(*i)++;
		while (str[*i + trimmed_len] != '\"')
			trimmed_len++;
		trimmed = ft_strndup(&str[*i], trimmed_len++);
	}
	else
	{
		while (ft_is_word_character(str[*i + trimmed_len]))
			trimmed_len++;
		trimmed = ft_strndup(&str[*i], trimmed_len);
	}
	if (!trimmed)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	expanded = ft_expand(trimmed, envp);
	free(trimmed);
	*i += (int)trimmed_len;
	return (expanded);
}
