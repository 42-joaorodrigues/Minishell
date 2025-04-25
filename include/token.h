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

#ifndef TOKEN_H
# define TOKEN_H

# include "jal_list.h"

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

// Token_List
t_list				*ft_token_list(const char *str);

// Util
t_token_type		ft_token_type(const char *value);
t_list				*ft_lstnew_token(t_token_type type, char *value);
void				ft_free_token(void *token);

#endif // TOKEN_H
