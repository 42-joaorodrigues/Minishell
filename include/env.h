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

# define EXTRA_SLOTS 32

typedef struct s_env
{
	char	**array;
	int		count;
	int		capacity;
}			t_env;

// Env
int			ft_init_env(t_env *env, char **envp);
int			ft_set_env(t_env *env, const char *key, const char *value);
const char	*ft_get_env(const char **envp, const char *key);
void		ft_unset_env(t_env *env, const char *key);

// Print
void		ft_print_env_fd(char **envp, int fd_out);

#endif // ENV_H
