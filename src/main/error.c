/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:01:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/02 13:32:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "minishell.h"
#include <unistd.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_puterror(const char *errstr)
{
	write(2, NAME, ft_strlen(NAME));
	write(2, ": ", 2);
	write(2, errstr, ft_strlen(errstr));
}

int	ft_print_error(const int errno)
{
	if (errno == E_MEM_ALLOC)
		ft_puterror("memory allocation failed\n");
	else if (errno == E_SYNTAX)
		ft_puterror("syntax error\n");
	return (errno);
}
