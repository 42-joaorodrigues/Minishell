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
#define EXEC_INT_H

#include "command.h"

// Execv
int		ft_execv(t_command *cmd, char **envp);
// Child
void	ft_child(t_command *cmd, char **envp);
// Path
char	*ft_path(char *cmd, char **envp);

#endif //EXEC_INT_H
