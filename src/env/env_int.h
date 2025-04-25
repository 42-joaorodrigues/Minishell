/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:33:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/15 14:33:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_PRIVATE_H
#define ENV_PRIVATE_H

#include "env.h"

int		ft_key_matches(const char *var, const char *key);
int		ft_add_slots_env(t_env *env);
char	*ft_create_env_entry(const char *key, const char *value);

#endif //ENV_PRIVATE_H
