/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:14:57 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/12 13:15:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_int.h"
#include "jal_error.h"
#include "jal_string.h"

int	ft_init_env(t_env *env, char **envp)
{
	env->array = ft_strarrdup(envp);
	if (!env->array)
		return (1);
	env->count = (int)ft_strarrcount(envp);
	env->capacity = env->count;
	return (ft_add_slots_env(env));
}

int	ft_set_env(t_env *env, const char *key, const char *value)
{
	int		i;
	char	*new_var;

	new_var = ft_create_env_entry(key, value);
	if (!new_var)
		return (ft_error("memory allocation failed", E_NOMEM));
	i = -1;
	while (++i < env->count)
		if (ft_key_matches(env->array[i], key))
		{
			free(env->array[i]);
			env->array[i] = new_var;
			return (0);
		}
	if (env->count == env->capacity)
		if (ft_add_slots_env(env) != 0)
			return (1);
	env->array[env->count++] = new_var;
	env->array[env->count] = NULL;
	return (0);
}

const char	*ft_get_env(const char **envp, const char *key)
{
	int	i;

	if (!envp || !key)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_key_matches(envp[i], key))
			return (&envp[i][ft_strlen(key) + 1]);
		i++;
	}
	return (NULL);
}

void	ft_unset_env(t_env *env, const char *key)
{
	int i;

	i = 0;
	while (env->array[i])
	{
		if (ft_key_matches(env->array[i], key))
		{
			free(env->array[i]);
			while (i < env->count - 1)
			{
				env->array[i] = env->array[i + 1];
				i++;
			}
			env->array[i] = NULL;
			env->count--;
			return ;
		}
		i++;
	}
}