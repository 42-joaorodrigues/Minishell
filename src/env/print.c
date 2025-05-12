/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:33:47 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/10 16:34:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "jal_print.h"
#include "jal_string.h"

void	ft_print_env_fd(char **envp, const int fd_out)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], fd_out);
		if (*(ft_strchr(envp[i], '=') + 1) == '\0')
			ft_putstr_fd("''", fd_out);
		ft_putstr_fd("\n", fd_out);
		i++;
	}
}
