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
	const char	*pwd;
	const char	*home;
	char		*path;

	pwd = ft_get_env(envp, "PWD");
	if (!pwd)
		return (ft_strdup("favela_shell"));
	home = ft_get_env(envp, "HOME");
	if (home && ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		if (pwd[ft_strlen(home)] == '\0')
			path = ft_strdup("~");
		else if (pwd[ft_strlen(home)] == '/')
			path = ft_strjoin("~", pwd + ft_strlen(home));
		else
			path = ft_strdup(pwd);
	}
	else
		path = ft_strdup(pwd);
	return (path);
}

char	*ft_prompt(const char **envp, const int colour)
{
	char	*prompt;
	char	*path;

	if (colour)
	{
		prompt = ft_strdup(YELLOW);
		path = ft_path(envp);
		prompt = ft_strjoin_free(prompt, path, 3);
		if (*ft_status_code() == 0)
			prompt = ft_strjoin_free(prompt, GREEN, 1);
		else
			prompt = ft_strjoin_free(prompt, PINK, 1);
		prompt = ft_strjoin_free(prompt, " ❯ ", 1);
		prompt = ft_strjoin_free(prompt, RESET, 1);
	}
	else
		prompt = ft_strdup("favela_shell > ");
	if (!prompt)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	return (prompt);
}
