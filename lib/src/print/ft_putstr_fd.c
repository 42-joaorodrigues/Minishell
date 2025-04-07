/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:31:24 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/26 15:32:44 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_print.h"
#include <unistd.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * Writes a String on the given file descriptor.
 *
 * @param s String to write.
 * @param fd File Descriptor to write on.
 */
void	ft_putstr_fd(char *s, const int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
