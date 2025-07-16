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
# include "env.h"

int		ft_is_builtin(const char *cmd);
void	ft_exec_builtin(t_command *command, char ***envp);

int		ft_echo(t_command *command);
int		ft_cd(t_command *cd, char ***envp);
int		ft_pwd(t_command *cmd, const char **envp);
int		ft_export(t_command *command, char ***envp);
int		ft_unset(t_command *cmd, char ***envp);
int		ft_env(t_command *cmd, const char **envp);
int		ft_exit(t_command *cmd, char **envp);

#endif // BUILTIN_H
