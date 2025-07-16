/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:12:18 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/12 13:12:24 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

// Env
int			ft_set_env(char ***envp, const char *key, const char *value);
const char	*ft_get_env(const char **envp, const char *key);
void		ft_unset_env(char ***envp, const char *key);
void		ft_print_env_fd(const char **envp, int fd_out);
void		ft_free_envp(char **envp);

#endif // ENV_H
