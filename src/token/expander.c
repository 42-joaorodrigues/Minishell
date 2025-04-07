/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:28:09 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_string.h"
#include "token.h"
#include "util.h"
#include <stdlib.h>

static ssize_t	ft_get_expanded_var_len(const t_prog *prog, const char *str,
		int *i)
{
	char	*name;
	char	*value;
	ssize_t	var_len;

	name = ft_extract_var_name(str, i);
	if (!name)
		return (-1);
	if (*name)
	{
		value = ft_get_var_value(prog, name);
		if (!value)
			return (free(name), -1);
		var_len = (ssize_t)ft_strlen(value);
		free(value);
	}
	else
		var_len = 1;
	free(name);
	return (var_len);
}

static ssize_t	ft_get_expanded_len(const t_prog *prog, const char *str)
{
	ssize_t	len;
	ssize_t	var_len;
	int		i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			var_len = ft_get_expanded_var_len(prog, str, &i);
			if (var_len < 0)
				return (-1);
			len += var_len;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	ft_expand_var(const t_prog *prog, t_expand *exp)
{
	char	*var_name;
	char	*var_value;
	int		k;

	var_name = ft_extract_var_name(exp->src, &exp->i);
	if (!var_name)
		return (ERROR);
	if (!*var_name)
		exp->dest[exp->j++] = '$';
	else
	{
		var_value = ft_get_var_value(prog, var_name);
		if (!var_value)
			return (free(var_name), ERROR);
		k = 0;
		while (var_value[k])
			exp->dest[exp->j++] = var_value[k++];
		free(var_value);
	}
	free(var_name);
	return (SUCCESS);
}

int	ft_init_expand(t_expand *exp, const t_prog *prog, char *src)
{
	ssize_t	len;

	len = ft_get_expanded_len(prog, src);
	if (len < 0)
		return (ERROR);
	exp->dest = malloc(len + 1);
	if (!exp->dest)
		return (ERROR);
	exp->src = src;
	exp->i = 0;
	exp->j = 0;
	return (SUCCESS);
}

char	*ft_expand(const t_prog *prog, char *str)
{
	t_expand	exp;

	if (!str)
		return (NULL);
	if (ft_init_expand(&exp, prog, str) == ERROR)
		return (NULL);
	while (exp.src[exp.i])
	{
		if (exp.src[exp.i] == '$')
		{
			exp.i++;
			if (ft_expand_var(prog, &exp) == ERROR)
				return (free(exp.dest), NULL);
		}
		else
			exp.dest[exp.j++] = exp.src[exp.i++];
	}
	exp.dest[exp.j] = '\0';
	return (exp.dest);
}
