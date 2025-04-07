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

#include "jal_list.h"
#include "jal_string.h"
#include "token.h"
#include <readline/readline.h>
#include <stdlib.h>

t_token	*ft_get_token_symbol(const char *input, int *i)
{
	char	*sym;

	if ((input[*i] == '<' && input[*i + 1] == '<') || (input[*i] == '>'
			&& input[*i + 1] == '>'))
		sym = ft_strndup(&input[*i], 2);
	else
		sym = ft_strndup(&input[*i], 1);
	if (!sym)
		return (NULL);
	*i += (int)ft_strlen(sym);
	return (ft_new_token(ft_get_token_type(sym), sym));
}

static char	*ft_trim_single_quotes(const char *str, int *i)
{
	char	*trimmed;
	int		trimmed_len;

	trimmed_len = 0;
	(*i)++;
	while (str[*i + trimmed_len] != '\'')
		trimmed_len++;
	trimmed = ft_strndup(&str[*i], trimmed_len++);
	*i += trimmed_len;
	return (trimmed);
}

static char	*ft_trim_and_expand(const t_prog *prog, const char *str, int *i)
{
	char	*trimmed;
	size_t	trimmed_len;
	char	*expanded;

	trimmed_len = 0;
	if (str[*i] == '\"')
	{
		(*i)++;
		while (str[*i + trimmed_len] != '\"')
			trimmed_len++;
		trimmed = ft_strndup(&str[*i], trimmed_len++);
	}
	else
	{
		while (ft_is_word_character(str[*i + trimmed_len]))
			trimmed_len++;
		trimmed = ft_strndup(&str[*i], trimmed_len);
	}
	expanded = ft_expand(prog, trimmed);
	free(trimmed);
	*i += (int)trimmed_len;
	return (expanded);
}

t_token	*ft_get_token_word(const t_prog *prog, const char *str, int *i)
{
	char	*join;
	char	*parsed;

	join = ft_strdup("");
	if (!join)
		return (NULL);
	while (str[*i] && str[*i] != ' ' && !ft_is_symbol(str[*i]))
	{
		if (str[*i] == '\'')
			parsed = ft_trim_single_quotes(str, i);
		else
			parsed = ft_trim_and_expand(prog, str, i);
		join = ft_strjoin_free(join, parsed, 3);
		if (!join)
			return (NULL);
	}
	return (ft_new_token(TOKEN_WORD, join));
}

t_list	*ft_get_token_list(const t_prog *prog, char *input)
{
	t_list	*token_list;
	t_list	*new_node;
	int		i;

	token_list = NULL;
	i = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (input[i])
		{
			if (ft_is_symbol(input[i]))
				new_node = ft_lstnew(ft_get_token_symbol(input, &i));
			else
				new_node = ft_lstnew(ft_get_token_word(prog, input, &i));
			if (!new_node)
				return (ft_lstclear(&token_list, ft_free_token), NULL);
			ft_lstadd_back(&token_list, new_node);
		}
	}
	return (token_list);
}
