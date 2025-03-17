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
#include "minishell.h"

static int ft_issym(const char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_list	*ft_lexer(char *input)
{
	t_list	*head;
	int	i;

	head = NULL;
	i = 0;
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (ft_issym(input[i]))
	}
	return (head);
}
