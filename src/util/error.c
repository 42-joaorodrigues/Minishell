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
#include "error.h"
#include <unistd.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_puterror(const char *err_msg)
{
	write(2, "Error\n", 6);
	write(2, PINK, ft_strlen(PINK));
	write(2, err_msg, ft_strlen(err_msg));
	write(2, RESET, ft_strlen(RESET));
}

static void	ft_standard_error(const int errno)
{
	if (errno == E_FORMAT)
		ft_puterror("Format: ./philo <n_philos> <die_time> <eat_time> "
			"<sleep_time> [n_meals]\n");
	else if (errno == E_MEM_ALLOC)
		ft_puterror("Memory allocation failed\n");
	else if (errno == E_CREATE_THREAD)
		ft_puterror("Failed to create thread\n");
	else if (errno == E_JOIN_THREAD)
		ft_puterror("Failed to join thread\n");
	else if (errno == E_MUTEX_INIT)
		ft_puterror("Failed to initiate mutex\n");
}

int	ft_print_error(const int errno)
{
	if (errno < 100)
		ft_standard_error(errno);
	else if (errno == E_PARENTHESES)
		ft_puterror("Closed parentheses failed\n");
	return (errno);
}
