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
# define COMMAND_H

# include "token.h"

typedef struct s_command
{
	char				*cmd;
	char				**args;
	int					fd_in;
	int					fd_out;
	int					pid;
	int					exit;
	struct s_command	*next;
}						t_command;

// Command
t_command				*ft_command(t_token *token);

// Utils
t_command				*ft_new_command(char **args, int fd_in, int fd_out,
							int exit_code);
void					ft_command_add_back(t_command **head, t_command *new);
void					ft_free_command(t_command *cmd);
void					ft_clear_command(t_command *head);

#endif // COMMAND_H
