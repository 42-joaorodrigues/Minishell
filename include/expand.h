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
#define EXPAND_H

#include "token.h"

int	ft_expand(t_list *token_list, const char **envp);

#endif //EXPAND_H
