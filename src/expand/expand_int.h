/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:19:43 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/15 19:19:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_INT_H
# define EXPAND_INT_H

char	*ft_expand_chunk(const char *str, int *index, const char *delimiter,
			const char **envp);

#endif // EXPAND_INT_H
