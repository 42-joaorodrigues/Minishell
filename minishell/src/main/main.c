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

#include "jal_string.h"

int	main(int ac, char **av, char **envp)
{
	int		colour;
	char	**envp_dup;

	colour = 0;
	if (ac == 2)
		if (!ft_strcmp(av[1], "colour"))
			colour = 1;
	envp_dup = ft_strarrdup(envp);
	if (!envp_dup)
		return (ft_error("memory allocation failed", E_NOMEM));
	ft_read(&envp_dup, colour);
	ft_free_envp(envp_dup);
	return (*ft_exit_code());
}
