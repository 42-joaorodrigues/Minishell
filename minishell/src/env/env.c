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
#include "jal_memory.h"
#include "jal_print.h"
#include "jal_string.h"

void	ft_free_envp(char **envp)
{
	ft_free_matrix((void **)envp);
}

void	ft_print_env_fd(const char **envp, const int fd_out)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd((char *)envp[i], fd_out);
		if (*(ft_strchr(envp[i], '=') + 1) == '\0')
			ft_putstr_fd("''", fd_out);
		ft_putstr_fd("\n", fd_out);
		i++;
	}
}

int	ft_set_env(char ***envp, const char *key, const char *value)
{
	int		i;
	char	*new;

	new = ft_new_entry(key, value);
	if (!new)
		return (ft_error("memory allocation failed", E_NOMEM));
	i = -1;
	while ((*envp)[++i])
		if (ft_key_exists((*envp)[i], key))
			return (free((*envp)[i]), (*envp)[i] = new, 0);
	*envp = ft_realloc_envp(*envp);
	if (!*envp)
		return (ft_error("memory allocation failed", E_NOMEM));
	i = 0;
	while ((*envp)[i])
		i++;
	(*envp)[i++] = new;
	(*envp)[i] = NULL;
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
		if (ft_key_exists(envp[i], key))
			return (&envp[i][ft_strlen(key) + 1]);
		i++;
	}
	return (NULL);
}

void	ft_unset_env(char ***envp, const char *key)
{
	int	i;

	i = 0;
	while ((*envp)[i])
	{
		if (ft_key_exists((*envp)[i], key))
		{
			free((*envp)[i]);
			while ((*envp)[i])
			{
				(*envp)[i] = (*envp)[i + 1];
				i++;
			}
			(*envp)[i] = NULL;
			return ;
		}
		i++;
	}
}
