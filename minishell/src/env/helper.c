/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:15:43 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/12 13:15:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_int.h"
#include "jal_error.h"
#include "jal_memory.h"
#include "jal_string.h"

int	ft_key_exists(const char *var, const char *key)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	return (ft_strncmp(var, key, key_len) == 0 && var[key_len] == '=');
}

char	**ft_realloc_envp(char **envp)
{
	char	**new;
	int		i;

	new = malloc((ft_strarrcount(envp) + 1 + 1) * sizeof(char *));
	if (!new)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	i = -1;
	while (envp[++i])
		new[i] = envp[i];
	new[i] = NULL;
	return (new);
}

char	*ft_new_entry(const char *key, const char *value)
{
	char	*entry;

	if (!key || !value)
		return (NULL);
	entry = malloc((ft_strlen(key) + 1 + ft_strlen(value) + 1));
	if (!entry)
		return (NULL);
	ft_strcpy(entry, key);
	ft_strcat(entry, "=");
	ft_strcat(entry, value);
	return (entry);
}
