/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:29:26 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/19 16:29:29 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stddef.h>

void	ft_init_prog(t_prog *prog)
{
	prog->exit_code = 0;
	prog->token_list = NULL;
	prog->command_list = NULL;
}
