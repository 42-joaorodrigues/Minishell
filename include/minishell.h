/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/01 11:57:18 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "jal_list.h"

# define NAME "favela_shell"
# define PROMPT "favela_shell > "

typedef struct s_program
{
	char	**envp;
	int		last_cmd_exit_code;
	int		exit_code;
}			t_prog;

#endif // MINISHELL_H
