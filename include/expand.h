/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:52:41 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/25 14:52:43 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "token.h"

// Token
t_token	*ft_expand(const t_token *token, const char **envp);
// Str
char	*ft_expand_str(char *str, const char **envp);

#endif // EXPAND_H
