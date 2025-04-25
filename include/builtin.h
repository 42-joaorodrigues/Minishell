/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:02:59 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/04 15:03:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "command.h"
# include "minishell.h"

int		ft_is_builtin(const char *cmd);
int		ft_exec_builtin(t_prog *prog, const t_command *command);

void	ft_exec_echo(const t_command *cmd);
void	ft_exec_cd(t_prog *prog, const t_command *cd);
int		ft_exec_pwd(t_prog *prog, const t_command *cmd);

#endif // BUILTIN_H
