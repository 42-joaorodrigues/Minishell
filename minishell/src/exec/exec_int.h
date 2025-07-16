/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:13:50 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 21:13:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_INT_H
# define EXEC_INT_H

# include "command.h"

// Execv
int		ft_execv(t_command *head, t_command *cmd, char **envp, int *pid_ref);
// Child
void	ft_child(t_command *head, t_command *cmd, char **envp);
// Path
char	*ft_path(char *cmd, char **envp);
// Close
void	ft_close_fd(t_command *cmd);

#endif // EXEC_INT_H
