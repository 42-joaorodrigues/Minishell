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

enum		e_error
{
	E_QUOTES = 100,
	E_CD_NO_PATH,
	E_CD_INVALID_PATH,
	E_GETCWD,
	E_PWD_ARGS,
	E_OPEN
};

typedef struct s_program
{
	t_env	*env;
	int		last_cmd_exit;
}			t_prog;

// Read
int			ft_read_input(t_env *env);

#endif // MINISHELL_H
