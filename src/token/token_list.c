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

#include "jal_error.h"
#include "jal_string.h"
#include "minishell.h"
#include "token.h"

static char	*ft_extract_symbol_value(const char *str)
{
	char	*value;

	if ((*str == '<' && *(str + 1) == '<') || (*str == '>' && *(str
				+ 1) == '>'))
		value = ft_strndup(str, 2);
	else
		value = ft_strndup(str, 1);
	if (!value)
		ft_error("memory allocation failed", E_NOMEM);
	return (value);
}

static char	*ft_extract_quoted_value(const char *str)
{
	char	*value;
	size_t	i;
	char	quote;

	quote = *str;
	i = 1;
	while (*(str + i) && *(str + i) != quote)
		i++;
	if (*(str + i) == '\0')
		return (ft_error("unclosed quotes", E_QUOTES), NULL);
	value = ft_strndup(str, i + 1);
	if (!value)
		ft_error("memory allocation failed", E_NOMEM);
	return (value);
}

static char	*ft_extract_word_value(const char *str)
{
	char	*value;
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != ' ' && *(str + i) != '<' && *(str
			+ i) != '>' && *(str + i) != '|' && *(str + i) != '\'' && *(str
		+ i) != '\"')
		i++;
	value = ft_strndup(str, i);
	if (!value)
		ft_error("memory allocation failed", E_NOMEM);
	return (value);
}

static t_list	*ft_create_token_node(const char *str, int *i)
{
	t_list			*node;
	char			*value;
	t_token_type	type;

	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		value = ft_extract_symbol_value(str + *i);
	else if (str[*i] == '\'' || str[*i] == '\"')
		value = ft_extract_quoted_value(str + *i);
	else
		value = ft_extract_word_value(str + *i);
	if (!value)
		return (NULL);
	*i += ft_strlen(value);
	type = ft_token_type(value);
	node = ft_lstnew_token(type, value);
	if (!node)
		return (free(value), ft_error("memory allocation failed", E_NOMEM),
			NULL);
	return (node);
}

t_list	*ft_token_list(const char *str)
{
	t_list *token_list;
	t_list *new_node;
	int i;

	token_list = NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			new_node = ft_create_token_node(str, &i);
			if (!new_node)
				return (ft_lstclear(&token_list, ft_free_token), NULL);
			ft_lstadd_back(&token_list, new_node);
		}
	}
	return (token_list);
}