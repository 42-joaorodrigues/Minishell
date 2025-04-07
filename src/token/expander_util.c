/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:12:27 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/03 18:12:37 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_char.h"
#include "jal_conversion.h"
#include "jal_string.h"
#include "minishell.h"
#include "token.h"
#include "util.h"

char	*ft_get_var_value(const t_prog *prog, const char *var_name)
{
	if (*var_name == '?')
		return (ft_itoa(prog->last_cmd_exit_code));
	return (ft_get_env_value(ft_get_env_ptr(prog->envp, var_name)));
}

char	*ft_extract_var_name(const char *str, int *i)
{
	int j;

	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_strdup("?"));
	}
	j = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	return (ft_strndup(&str[j], *i - j));
}