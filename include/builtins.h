/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:34:38 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 13:34:39 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/* Funções dos Builtins */
int	builtin_echo(char **args);
int	builtin_cd(char **args, t_shell *shell);
int	builtin_pwd(void);
int	builtin_export(char **args, t_shell *shell);
int	builtin_unset(char **args, t_shell *shell);
int	builtin_env(t_shell *shell);
int	builtin_exit(char **args, t_shell *shell);

#endif
