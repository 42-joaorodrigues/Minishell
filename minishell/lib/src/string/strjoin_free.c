/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:37:24 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/02 14:37:27 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"

char	*ft_strjoin_free(char *s1, char *s2, const int to_free)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (s1 && to_free & 1)
		free(s1);
	if (s2 && to_free & 2)
		free(s2);
	return (joined);
}
