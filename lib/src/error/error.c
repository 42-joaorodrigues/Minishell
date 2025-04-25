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

#include "jal_error.h"
#include <unistd.h>

int	*ft_exit_code(void)
{
	static int	exit_code = 0;
	return (&exit_code);
}

static int	ft_static_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_puterror(const char *err_str)
{
	write(2, ERROR_PINK, ft_static_strlen(ERROR_PINK));
	write(2, "error: ", 7);
	write(2, ERROR_RESET, ft_static_strlen(ERROR_RESET));
	write(2, err_str, ft_static_strlen(err_str));
	write(2, "\n", 1);
}

int	ft_error(const char *err_str, const int err_no)
{
	if (err_str)
		ft_puterror(err_str);
	*ft_exit_code() = err_no;
	return (err_no);
}
