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
#include "env.h"

int		ft_is_builtin(const char *cmd);
void	ft_exec_builtin(t_command *command, t_env *env);

int	ft_echo(const t_command *command);
int	ft_cd(const t_command *cd, t_env *env);
int	ft_pwd(const t_command *cmd, t_env *env);
int	ft_export(const t_command *command, t_env *env);
int	ft_unset(const t_command *cmd, t_env *env);
int	ft_env(const t_command *cmd, t_env *env);
int	ft_exit(t_command *cmd, t_env *env);

#endif // BUILTIN_H
