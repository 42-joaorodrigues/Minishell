/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:00:26 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 23:00:28 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_colour.h"
#include "jal_error.h"
#include "jal_string.h"
#include "minishell.h"
#include "status.h"

static char	*ft_path(const char **envp)
{
	const char	*env_path;
	char		*path;
	int			i;

	env_path = ft_get_env(envp, "PWD");
	if (env_path)
	{
		if (ft_strncmp(env_path, "/home/", 6) == 0)
		{
			i = 6;
			while (env_path[i] && env_path[i] != '/')
				i++;
			path = ft_strjoin("~", env_path + i);
		}
		else
			path = ft_strdup(env_path);
	}
	else
		path = ft_strdup("favela_shell");
	if (!path)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	return (path);
}

char	*ft_prompt(const char **envp)
{
	char		*prompt;
	char		*path;

	prompt = ft_strdup(YELLOW);
	if (!prompt)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	path = ft_path(envp);
	if (!path)
		return (free(prompt), NULL);
	prompt = ft_strjoin_free(prompt, path, 3);
	if (!prompt)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	if (*ft_status_code() == 0)
		prompt = ft_strjoin_free(prompt, " \033[38;5;121m❯\033[0m ", 1);
	else
		prompt = ft_strjoin_free(prompt, " \033[38;5;211m❯\033[0m ", 1);
	if (!prompt)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	return (prompt);
}
