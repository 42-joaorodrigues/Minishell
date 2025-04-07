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
#include <readline/readline.h>
#include <stdlib.h>

char	*ft_get_env_value(char *env_ptr)
{
	char	*value;
	int		i;

	if (!env_ptr)
		return (ft_strdup(""));
	i = 0;
	while (env_ptr[i] && env_ptr[i] != '=')
		i++;
	if (env_ptr[i])
		i++;
	value = ft_strdup(&env_ptr[i]);
	if (!value)
		return (NULL);
	return (value);
}

char	*ft_get_env_ptr(char **envp, const char *var_name)
{
	int		i;
	size_t	len;

	len = ft_strlen(var_name);
	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], var_name, len) && (envp[i][len] == '='
				|| envp[i][len] == '\0'))
			return (envp[i]);
	return (NULL);
}
