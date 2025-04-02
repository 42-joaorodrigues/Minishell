/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:28:09 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_char.h"
#include "jal_conversion.h"
#include "jal_string.h"
#include "minishell.h"
#include <stdlib.h>

static int	ft_is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

char	*ft_get_env_value(const char *var_name)
{
	char	*value;

	if (!var_name || !*var_name)
		return (ft_strdup(""));
	if (var_name[0] == '?')
		return (0);
	if (ft_isdigit(var_name[0]))
		return (ft_strdup(""));
	value = getenv(var_name);
	if (value)
		return (ft_strdup(value));
	return (ft_strdup(""));
}

int	ft_get_var_name_len(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '{')
	{
		i++;
		while (str[i] && str[i] != '}')
			i++;
		if (str[i] == '}')
			return (i + 1);
		return (0);
	}
	if (str[i] == '?' || ft_isdigit(str[i]))
		return (1);
	while (str[i] && ft_is_var_char(str[i]))
		i++;
	return (i);
}

char	*ft_charjoin(char *s, char c)
{
	char	*result;
	int		i;

	result = malloc(ft_strlen(s) + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}
