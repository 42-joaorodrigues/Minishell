/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:00:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/27 15:08:36 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"
#include "minishell.h"
#include <stdlib.h>

int	ft_is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

static int	ft_is_escaped_char(const char *str, int i)
{
	return (i > 0 && str[i - 1] == '\\');
}

char	*ft_remove_quotes(char *str, char quote_type)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != quote_type)
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	ft_count_quotes(const char *str, char quote_type)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == quote_type && !ft_is_escaped_char(str, i))
			count++;
		i++;
	}
	return (count);
}
