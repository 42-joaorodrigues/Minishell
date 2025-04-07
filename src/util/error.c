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
	write(2, PINK, ft_strlen(PINK));
	write(2, NAME, ft_strlen(NAME));
	write(2, " ❯ ", 5);
	write(2, RESET, ft_strlen(RESET));
	write(2, errstr, ft_strlen(errstr));
	write(2, "\n", 1);
}

int	ft_print_error(t_prog *prog, const int errno)
{
	if (errno == E_MEM_ALLOC)
		ft_puterror("memory allocation failed");
	else if (errno == E_QUOTES)
		ft_puterror("syntax error : unclosed quotes");
	else if (errno == E_CD_NO_PATH)
		ft_puterror("cd : path required");
	else if (errno == E_CD_INVALID_PATH)
		ft_puterror("cd : invalid path");
	else if (errno == E_PWD_ARGS)
		ft_puterror("pwd : too much args");
	prog->exit_code = errno;
	return (ERROR);
}
