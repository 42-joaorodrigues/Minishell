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

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}					t_token;

// Token_List
t_token				*ft_token(const char *str);

// Util
t_token_type		ft_token_type(const char *value);
t_token				*ft_new_token(char *value);
void				ft_token_add_back(t_token **head, t_token *new);
void				ft_token_free(t_token *token);
void				ft_token_clear(t_token *head);

#endif // TOKEN_H
