/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:45:02 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/12 16:45:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

# define S_QUOTES 70
# define S_TKN_SYNTAX 2
# define S_CD_NO_PATH 1
# define S_CD_ARGS 1
# define S_CD_INVALID_PATH 1
# define S_GETCWD 1
# define S_EXPORT_ARGS 1
# define S_PWD_ARGS 1
# define S_ENV_ARGS 1
# define S_EXIT_NUM 2
# define S_EXIT_ARGS 1
# define S_FORK 1
# define S_CMD_NOT_FOUND 127
# define S_NO_PERM 1

int	*ft_status_code(void);
int	ft_status(const char *prefix, const char *str, int status);

int	*ft_last_status_code(void);

#endif // STATUS_H
