/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:39:16 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/03 18:39:22 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
#define COMMAND_H

#include "minishell.h"

typedef struct s_command
{
	char	*cmd;
	char	**args;
	int		input_fd;
	int		output_fd;
}			t_command;

void		ft_exec_command(t_prog *prog, t_list **command_list);

// Command
t_list		*ft_commands_from_tokens(t_list **token_list);

// Command Utils
t_command	*ft_init_command(void);
void		ft_free_command(void *command);

#endif //COMMAND_H
