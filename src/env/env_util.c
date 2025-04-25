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
#include "jal_string.h"

int	ft_key_matches(const char *var, const char *key)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	return (ft_strncmp(var, key, key_len) == 0 && var[key_len] == '=');
}

int	ft_add_slots_env(t_env *env)
{
	char	**new_array;
	int		i;

	new_array = malloc((env->capacity + EXTRA_SLOTS + 1) * sizeof(char *));
	if (!new_array)
		return (ft_error("memory allocation failed", E_NOMEM));
	i = 0;
	while (i < env->count)
	{
		new_array[i] = env->array[i];
		i++;
	}
	new_array[i] = NULL;
	free(env->array);
	env->array = new_array;
	env->capacity += EXTRA_SLOTS;
	return (0);
}

char	*ft_create_env_entry(const char *key, const char *value)
{
	char *entry;

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