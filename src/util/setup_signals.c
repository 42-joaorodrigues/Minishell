/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:09:02 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 18:09:04 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <signal.h>
#include <stdio.h>

static void signal_handler(int sig)
{
    if (sig == SIGINT)
    {
        /* Por exemplo, imprimir uma nova linha e reexibir o prompt */
        write(1, "\n", 1);
        /* Você pode chamar uma função para exibir o prompt novamente, se necessário */
    }
}

void setup_signals(void)
{
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);
    /* Você pode configurar outros sinais (como SIGQUIT) se necessário */
}
