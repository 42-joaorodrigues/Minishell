/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:20:01 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 20:20:01 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "env.h"
#include "exec_int.h"
#include "jal_error.h"
#include "jal_memory.h"
#include "jal_string.h"

char	*ft_search_path(char **path_array, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (path_array[i])
	{
		path = ft_strjoin(path_array[i], "/");
		if (!path)
			return (ft_error("memory allocation failed", E_NOMEM), NULL);
		path = ft_strjoin_free(path, cmd, 1);
		if (!path)
			return (ft_error("memory allocation failed", E_NOMEM), NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	path = ft_strdup("");
	if (!path)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	return (path);
}

char	*ft_path(char *cmd, char **envp)
{
	char	*path;
	char	*env_path;
	char	**path_array;

	if (!cmd)
		return (ft_strdup(""));
	env_path = (char *)ft_get_env((const char **)envp, "PATH");
	if (!env_path || cmd[0] == '/' || cmd[0] == '.')
	{
		env_path = ft_strdup(cmd);
		if (!env_path)
			ft_error("memory allocation failed", E_NOMEM);
		return (env_path);
	}
	path_array = ft_split(env_path, ':');
	if (!path_array)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	path = ft_search_path(path_array, cmd);
	ft_free_matrix((void **)path_array);
	return (path);
}
