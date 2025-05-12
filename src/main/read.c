/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:16:02 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/23 18:16:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "jal_error.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "command.h"
#include "expand.h"
#include "exec.h"
#include "sig.h"
#include "status.h"

static int	ft_execute_line(const char *line, t_env *env)
{
	t_token		*token;
	t_command	*command;

	token = ft_token(line);
	if (!token)
		return (*ft_exit_code());
	if (ft_expand_token(token, (const char **)env->array) != 0)
		return (ft_clear_token(token), *ft_exit_code());
	command = ft_command(token);
	ft_clear_token(token);
	if (!command)
		return (*ft_exit_code());
	ft_exec(command, env);
	ft_clear_command(command);
	return (0);
}

int	ft_read(t_env *env)
{
	char	*line;
	char	*prompt;

	while (1)
	{
		ft_signal();
		prompt = ft_prompt((const char **)env->array);
		line = readline(prompt);
		free(prompt);
		if (!line)
			break ;
		if (*line)
		{
			add_history(line);
			if (ft_execute_line(line, env) != 0 && *ft_status_code() != S_QUOTES)
				return (*ft_exit_code());
		}
		free(line);
	}
	rl_clear_history();
	return (0);
}