/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/13 15:02:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "util.h"
#include "jal_list.h"

#define NAME "favela_shell"
#define PROMPT YELLOW NAME RESET GREEN " ❯ " RESET

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC
}   t_token_type;

typedef struct	s_token
{
	t_token_type    type;
	char            *value;
}				t_token;

typedef struct	s_program
{
	t_list		*token_list;
	int			exit_code;
}				t_prog;

// init
void	ft_init_prog(t_prog *prog);

// parser
int		ft_parser(t_prog *prog, const char *input);

// lexer
int		ft_lexer(t_list **token_list, const char *input);

// token_utils
t_token	*ft_new_token(const t_token_type type, char *value);
void	ft_free_token(void *token);

#endif //MINISHELL_H
