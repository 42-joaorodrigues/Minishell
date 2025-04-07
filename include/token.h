/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:06:13 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/03 18:06:26 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_C_H
# define TOKEN_C_H

#include "minishell.h"

typedef struct s_expand
{
	char					*src;
	int						i;
	char					*dest;
	int						j;
}							t_expand;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC
}							t_token_type;

typedef struct s_token
{
	t_token_type			type;
	char					*value;
}							t_token;

// Expand
char						*ft_expand(const t_prog *prog, char *src);

// Expander Utils
char						*ft_get_var_value(const t_prog *prog,
								const char *var_name);
char						*ft_extract_var_name(const char *str, int *i);

// Char Utils
int							ft_is_symbol(const char c);
int							ft_is_quote(const char c);
int							ft_is_word_character(const char c);

// Token Utils
t_token_type				ft_get_token_type(char *s);
t_token						*ft_new_token(const t_token_type type, char *value);
void						ft_free_token(void *token);

// Token
t_list						*ft_get_token_list(const t_prog *prog, char *input);

#endif // TOKEN_C_H
