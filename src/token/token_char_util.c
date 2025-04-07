/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_char_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:04:04 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/03 18:04:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	ft_is_symbol(const char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	ft_is_quote(const char c)
{
	return (c == '\'' || c == '\"');
}

int	ft_is_word_character(const char c)
{
	return (c && c != ' ' && !ft_is_quote(c) && !ft_is_symbol(c));
}
