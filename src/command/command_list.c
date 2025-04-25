/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:11:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 10:15:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "jal_list.h"
#include "jal_print.h"
#include "jal_string.h"
#include "token.h"
#include "util.h"
#include <fcntl.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_count_command_args(t_list *token_list)
{
	int	count;

	count = 0;
	if (!token_list)
		return (count);
	while (token_list && ((t_token *)token_list->content)->type == TOKEN_WORD)
	{
		token_list = token_list->next;
		count++;
	}
	return (count);
}

static char	**ft_get_command_args(t_list **token_list)
{
	char	**args;
	int		i;

	if (!token_list || !*token_list)
		return (NULL);
	args = malloc((ft_count_command_args(*token_list) + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = -1;
	while (*token_list
		&& ((t_token *)(*token_list)->content)->type == TOKEN_WORD)
	{
		args[++i] = ((t_token *)(*token_list)->content)->value;
		ft_lstdel_safely(token_list, *token_list, free);
	}
	args[++i] = NULL;
	return (args);
}

static int	ft_handle_heredoc(t_command *command, const char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
		return (ERROR);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = readline("");
	while (line && ft_strcmp(line, delimiter) != 0)
	{
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = readline("");
	}
	if (line)
		free(line);
	close(pipe_fd[1]);
	command->input_fd = pipe_fd[0];
	return (SUCCESS);
}

static int	ft_get_command_fds(t_list **token_list, t_command *command)
{
	t_token	*current;
	t_token	*redirect;

	if (!token_list)
		return (ERROR);
	while (*token_list
		&& ((t_token *)(*token_list)->content)->type != TOKEN_PIPE)
	{
		current = (t_token *)(*token_list)->content;
		if (current->type > 0)
		{
			redirect = (t_token *)(*token_list)->next->content;
			if (current->type == TOKEN_REDIRECT_IN)
				command->input_fd = open(redirect->value, O_RDONLY);
			else if (current->type == TOKEN_REDIRECT_OUT)
				command->output_fd = open(redirect->value,
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else if (current->type == TOKEN_APPEND)
				command->output_fd = open(redirect->value,
						O_WRONLY | O_CREAT | O_APPEND, 0644);
			else if (current->type == TOKEN_HEREDOC)
				ft_handle_heredoc(command, redirect->value);
			ft_lstdel_safely(token_list, *token_list, ft_free_token);
		}
		ft_lstdel_safely(token_list, *token_list, ft_free_token);
	}
	return (SUCCESS);
}

t_command	*ft_get_command(t_list **token_list)
{
	t_command	*command;

	command = ft_init_command();
	if (!command)
		return (NULL);
	command->args = ft_get_command_args(token_list);
	if (!command->args)
		return (ft_free_command(command), NULL);
	command->cmd = ft_strdup(command->args[0]);
	if (!command->cmd)
		return (ft_free_command(command), NULL);
	if (ft_get_command_fds(token_list, command) != SUCCESS)
		return (ft_free_command(command), NULL);
	return (command);
}

t_list	*ft_commands_from_tokens(t_list **token_list)
{
	t_list		*command_list;
	t_command	*command;
	int			previous_pipe_fd[2];
	int			pipe_active;
	t_list		*new_node;

	command_list = NULL;
	pipe_active = 0;
	if (!token_list)
		return (NULL);
	while (*token_list)
	{
		command = ft_get_command(token_list);
		if (!command)
			return (ft_lstclear(&command_list, ft_free_command), NULL);
		if (pipe_active && command->input_fd == STDIN_FILENO)
			command->input_fd = previous_pipe_fd[0];
		else if (pipe_active)
			close(previous_pipe_fd[0]);
		if (*token_list
			&& ((t_token *)(*token_list)->content)->type == TOKEN_PIPE)
		{
			if (pipe(previous_pipe_fd) < 0)
				return (ft_free_command(command), ft_lstclear(&command_list,
						ft_free_command), NULL);
			if (command->output_fd == STDOUT_FILENO)
				command->output_fd = previous_pipe_fd[1];
			else
				close(previous_pipe_fd[1]);
			pipe_active = 1;
			ft_lstdel_safely(token_list, *token_list, ft_free_token);
		}
		else
			pipe_active = 0;
		new_node = ft_lstnew(command);
		if (!new_node)
		{
			ft_free_command(command);
			return (ft_lstclear(&command_list, ft_free_command), NULL);
		}
		ft_lstadd_back(&command_list, new_node);
	}
	return (command_list);
}
