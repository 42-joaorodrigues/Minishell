/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:28:09 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"
#include "minishell.h"
#include <stdlib.h>

static char	*ft_extract_var_name(const char *str, int len)
{
	if (str[0] == '{')
		return (ft_substr(str, 1, len - 2));
	return (ft_substr(str, 0, len));
}

static char	*ft_join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	if (s2)
		free(s2);
	return (result);
}

static char	*ft_handle_variable(const char *str, int *i, t_prog *prog)
{
	char	*var_name;
	char	*var_value;
	int		var_len;

	var_len = ft_get_var_name_len(str + *i + 1);
	if (var_len == 0)
	{
		(*i)++;
		return (ft_strdup("$"));
	}
	var_name = ft_extract_var_name(str + *i + 1, var_len);
	var_value = ft_get_env_value(var_name, prog);
	free(var_name);
	*i += var_len + 1;
	return (var_value);
}

char	*ft_expand_str(const char *str, t_prog *prog)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			temp = ft_handle_variable(str, &i, prog);
			result = ft_join_and_free(result, temp);
			continue ;
		}
		temp = ft_charjoin(result, str[i++]);
		free(result);
		result = temp;
	}
	return (result);
}
