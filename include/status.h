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
#define STATUS_H

enum e_status
{
	S_QUOTES = 100,
	S_CD_NO_PATH,
	S_CD_INVALID_PATH,
	S_GETCWD,
	S_UNSET_ARGS,
	S_ENV_ARGS,
	S_EXIT_NUM,
	S_EXIT_ARGS,
	S_FORK,
	S_CMD_NOT_FOUND
};

int	*ft_status_code();
int	ft_status(const char *str, const int status);

#endif //STATUS_H
