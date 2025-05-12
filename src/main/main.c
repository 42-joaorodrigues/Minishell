/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:25:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/31 16:53:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_error.h"
#include "jal_memory.h"
#include "minishell.h"
#include <stdlib.h>

int	main(int ac, char **av, char **envp)
{
	t_env	env;

	(void)ac;
	(void)av;
	if (ft_init_env(&env, envp) != 0)
		return (ft_free_matrix((void **)env.array), *ft_exit_code());
	if (ft_read(&env) != 0)
		return (ft_free_matrix((void **)env.array), *ft_exit_code());
	ft_free_matrix((void **)env.array);
	return (0);
}
