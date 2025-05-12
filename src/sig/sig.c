/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:39:27 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 18:42:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sig.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>

void	ft_handle_sigint(int signum)
{
	(void)signum;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_signal(void)
{
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
