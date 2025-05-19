/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:44:06 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/23 19:44:09 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "token.h"
#include "jal_error.h"
#include "jal_string.h"
#include "status.h"

static int	ft_valid(const t_token *token)
{
	while (token)
	{
		if ((token->type == TOKEN_REDIRECT_IN
				|| token->type == TOKEN_REDIRECT_OUT
				|| token->type == TOKEN_APPEND
				|| token->type == TOKEN_HEREDOC)
			&& (!token->next || token->next->type != TOKEN_WORD))
			return (0);
		if (token->type == TOKEN_PIPE
			&& (!token->next || token->next->type == TOKEN_PIPE))
			return (0);
		token = token->next;
	}
	return (1);
}

static int	ft_extract_helper(const char *str, const int *j)
{
	int		i;
	char	quote;

	i = *j;
	while (str[i] && str[i] != '<' && str[i] != '>' && str[i] != '|'
		&& str[i] != ' ')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				i++;
			if (str[i] == quote)
				i++;
			else
				return (ft_status("syntax", "unclosed quotes", S_QUOTES), -1);
		}
		else
			i++;
	}
	return (i);
}

static t_token	*ft_extract(const char *str, int *i)
{
	char			*result;
	int				j;

	j = *i;
	if (str[j] == '<' || str[j] == '>' || str[j] == '|')
	{
		if ((str[j] == '<' && str[j + 1] == '<')
			|| (str[j] == '>' && str[j + 1] == '>'))
			j += 2;
		else
			j++;
	}
	else
		j = ft_extract_helper(str, &j);
	if (j == -1)
		return (NULL);
	result = ft_strndup(str + *i, j - *i);
	if (!result)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	*i = j;
	return (ft_new_token(result));
}

t_token	*ft_token(const char *str)
{
	t_token	*head;
	t_token	*new;
	int		i;

	head = NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			new = ft_extract(str, &i);
			if (!new)
				return (ft_token_clear(head), NULL);
			ft_token_add_back(&head, new);
		}
	}
	if (!ft_valid(head))
	{
		ft_status("syntax", "unexpected token", S_TKN_SYNTAX);
		return (ft_token_clear(head), NULL);
	}
	return (head);
}
