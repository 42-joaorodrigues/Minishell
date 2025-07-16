/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:47:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 16:47:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"
#include "status.h"
#include <unistd.h>

int	*ft_status_code(void)
{
	static int	status = 0;

	return (&status);
}

int	ft_status(const char *prefix, const char *str, const int status)
{
	if (str)
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	*ft_status_code() = status;
	return (status);
}
