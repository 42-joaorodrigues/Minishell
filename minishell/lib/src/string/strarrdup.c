/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:12:16 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/10 14:12:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"

char	**ft_strarrdup(char **src)
{
	char	**dup;
	size_t	i;

	if (!src)
		return (NULL);
	dup = malloc((ft_strarrcount(src) + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = ft_strdup(src[i]);
		if (!dup[i])
		{
			while (i > 0)
				free(dup[--i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
