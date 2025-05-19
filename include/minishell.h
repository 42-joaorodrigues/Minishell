/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 11:57:18 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "env.h"

# define NAME "favela_shell"
# define PROMPT "favela_shell > "

// Read
void	ft_read(char ***envp, const int colour);
// Prompt
char	*ft_prompt(const char **envp, int colour);

#endif // MINISHELL_H
