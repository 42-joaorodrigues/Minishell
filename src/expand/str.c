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

#include "expand.h"
#include "expand_int.h"
#include "jal_error.h"
#include "jal_string.h"

char	*ft_double_quote(char *str, int *index, const char **envp)
{
	char	*result;
	char	*temp;
	char	*chunk;

	result = ft_strdup("");
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	*index += 1;
	while (str[*index] && str[*index] != '\"')
	{
		chunk = ft_expand_chunk(str, index, "$\"", envp);
		if (!chunk)
			return (free(result), NULL);
		temp = ft_strjoin_free(result, chunk, 3);
		if (!temp)
			return (free(result), ft_error("memory allocation failed", E_NOMEM),
				NULL);
		result = temp;
	}
	if (str[*index] == '\"')
		(*index)++;
	return (result);
}

char	*ft_single_quote(char *str, int *index)
{
	char	*result;
	int		i;
	int		start;

	start = *index + 1;
	i = start;
	while (str[i] && str[i] != '\'')
		i++;
	result = ft_strndup(&str[start], i - start);
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	if (str[i] == '\'')
		i++;
	*index = i;
	return (result);
}

char	*ft_unquoted(char *str, int *index, const char **envp)
{
	int		i;
	char	*result;
	char	*temp;
	char	*chunk;

	result = ft_strdup("");
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	i = *index;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
	{
		*index = i;
		chunk = ft_expand_chunk(str, index, "$\'\"", envp);
		if (!chunk)
			return (free(result), NULL);
		i = *index;
		temp = ft_strjoin_free(result, chunk, 3);
		if (!temp)
			return (free(result), ft_error("memory allocation failed", E_NOMEM),
				NULL);
		result = temp;
	}
	*index = i;
	return (result);
}

char	*ft_expand_str(char *str, const char **envp)
{
	int		i;
	char	*result;
	char	*temp;

	result = ft_strdup("");
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			temp = ft_single_quote(str, &i);
		else if (str[i] == '\"')
			temp = ft_double_quote(str, &i, envp);
		else
			temp = ft_unquoted(str, &i, envp);
		if (!temp)
			return (free(result), NULL);
		result = ft_strjoin_free(result, temp, 3);
		if (!result)
			return (ft_error("memory allocation failed", E_NOMEM), NULL);
	}
	return (result);
}
