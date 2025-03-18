/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:25:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/13 15:16:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include "jal_print.h"
#include "jal_string.h"
#include "util.h"
#include "minishell.h"

void	ft_print_tokens(t_list *token_list)
{
	t_list	*tmp;
	t_token	*token;
	char	*str_type;

	tmp = token_list;
	while (tmp)
	{
		token = (t_token *)tmp->content;
		str_type = NULL;
		if (token->type == TOKEN_WORD)
			str_type = "Word";
		else if (token->type == TOKEN_PIPE)
			str_type = "Pipe";
		else if (token->type == TOKEN_APPEND)
			str_type = "Append";
		else if (token->type == TOKEN_HEREDOC)
			str_type = "Heredoc";
		else if (token->type == TOKEN_REDIRECT_IN)
			str_type = "Redirect_in";
		else if (token->type == TOKEN_REDIRECT_OUT)
			str_type = "Redirect_out";
		ft_printf("Token: type = %s, value = '%s'\n", str_type, token->value);
		tmp = tmp->next;
	}
}

static void	ft_read_input(t_list **token_list)
{
	char	*input;

	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input)
			add_history(input);
		if (!ft_strcmp(input, "print_tokens"))
			ft_print_tokens(*token_list);
		else
			if (ft_lexer(token_list, input) == ERROR)
				break ;
		free(input);
	}
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{
	t_list	*token_list;

	(void)ac;
	(void)av;
	(void)envp;
	token_list = NULL;
	ft_read_input(&token_list);
	ft_lstclear(&token_list, ft_free_token);
	return (SUCCESS);
}
