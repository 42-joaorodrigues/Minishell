/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:16:02 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/19 14:28:25 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "exec.h"
#include "expand.h"
#include "jal_error.h"
#include "minishell.h"
#include "sig.h"
#include "token.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

#include "test.h"

static int	ft_execute_line(const char *line, char ***envp)
{
	t_token		*token;
	t_token		*expanded;
	t_command	*command;

	token = ft_token(line);
	if (!token)
		return (*ft_exit_code());
	expanded = ft_expand(token, (const char **)*envp);
	ft_token_clear(token);
	if (!expanded)
		return (*ft_exit_code());
	command = ft_command(expanded);
	ft_token_clear(expanded);
	if (!command)
		return (*ft_exit_code());
	ft_exec(command, envp);
	ft_clear_command(command);
	return (0);
}

void	ft_read(char ***envp, const int colour)
{
	char	*line;
	char	*prompt;

	while (1)
	{
		ft_signal();
		prompt = ft_prompt((const char **)*envp, colour);
		line = readline(prompt);
		free(prompt);
		if (!line)
			break ;
		if (*line)
		{
			add_history(line);
			ft_execute_line(line, envp);
			if (*ft_exit_code())
			{
				free(line);
				break ;
			}
		}
		free(line);
	}
	rl_clear_history();
}
