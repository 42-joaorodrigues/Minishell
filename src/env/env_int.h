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

#ifndef ENV_INT_H
# define ENV_INT_H

int		ft_key_exists(const char *var, const char *key);
char	**ft_realloc_envp(char **envp);
char	*ft_new_entry(const char *key, const char *value);

#endif // ENV_INT_H
