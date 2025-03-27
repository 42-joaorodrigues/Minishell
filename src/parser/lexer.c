/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:49:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/17 16:49:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <util.h>

#include "jal_string.h"
#include "minishell.h"

static int ft_issymbol(const char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_token_type	ft_get_token_type(char *s)
{
	if (s[0] == '|' && s[1] == '\0')
		return (TOKEN_PIPE);
	if (s[0] == '<' && s[1] == '\0')
		return (TOKEN_REDIRECT_IN);
	if (s[0] == '>' && s[1] == '\0')
		return (TOKEN_REDIRECT_OUT);
	if (ft_strncmp(s, ">>", 2) == 0)
		return (TOKEN_APPEND);
	if (ft_strncmp(s, "<<", 2) == 0)
		return (TOKEN_HEREDOC);
	if (s[0] == '\'')
		return (TOKEN_SQUOTE);
	if (s[0] == '\"')
		return (TOKEN_DQUOTE);
	return (TOKEN_WORD);
}

static int	ft_parse_sym(t_list **token_list, const char *input, int *i)
{
	char	*sym;
	t_token	*new_token;

	if (input[*i] == '<' && input[*i + 1] == '<')
		sym = ft_strndup(&input[*i], 2);
	else if (input[*i] == '>' && input[*i + 1] == '>')
		sym = ft_strndup(&input[*i], 2);
	else
		sym = ft_strndup(&input[*i], 1);
	if (!sym)
		return (ERROR);
	*i += (int)ft_strlen(sym);
	new_token = ft_new_token(ft_get_token_type(sym), sym);
	if (!new_token)
		return (ERROR);
	ft_lstadd_back(token_list, ft_lstnew(new_token));
	return (SUCCESS);
}

static int	ft_parse_word(t_list **token_list, const char *input, int *i)
{
	char	*word;
	t_token	*new_token;
	int		start;
	char	quote;

	start = *i;
	quote = 0;
	while (input[*i] && (quote || (input[*i] != ' ' && !ft_issymbol(input[*i]))))
	{
		if (!quote && (input[*i] == '\'' || input[*i] == '\"'))
			quote = input[*i];
		else if (quote && input[*i] == quote)
			quote = 0;
		(*i)++;
	}
	word = ft_strndup(&input[start], *i - start);
	if (!word)
		return (ERROR);
	new_token = ft_new_token(ft_get_token_type(word), word);
	if (!new_token)
		return (ERROR);
	ft_lstadd_back(token_list, ft_lstnew(new_token));
	return (SUCCESS);
}

int	ft_lexer(t_list **token_list, const char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (ft_issymbol(input[i]))
		{
			if (ft_parse_sym(token_list, input, &i) == ERROR)
				return (ERROR);
		}
		else if (input[i])
			if (ft_parse_word(token_list, input, &i) == ERROR)
				return (ERROR);
	}
	return (SUCCESS);
}
