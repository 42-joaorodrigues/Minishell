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

#include "status.h"
#include <unistd.h>
#include "jal_string.h"

int	*ft_status_code()
{
	static int	status = 0;
	return (&status);
}

int	ft_status(const char *str, const int status)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	*ft_status_code() = status;
	return (status);
}