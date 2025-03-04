/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:38:55 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/03/03 13:39:20 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/include/lib_string.h"
#include "../../include/minishell.h"
#include <dirent.h>

/*
 * Função: expand_wildcards
 * -------------------------
 * Recebe um padrão (geralmente "*") e retorna um array de strings com os nomes
 * dos arquivos do diretório atual que não começam com ponto.
 *
 * Retorna: Array de strings ou NULL em caso de erro.
 */
char	**expand_wildcards(const char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**files;
	int				count;
	int				i;

	if (!pattern || ft_strcmp(pattern, "*"))
		return (NULL);
	dir = opendir(".");
	if (!dir)
		return (NULL);
	count = 0;
	while ((entry = readdir(dir)))
		if (entry->d_name[0] != '.')
			count++;
	closedir(dir);
	files = malloc(sizeof(char *) * (count + 1));
	if (!files)
		return (NULL);
	dir = opendir(".");
	if (!dir)
		return (NULL);
	i = 0;
	while ((entry = readdir(dir)))
		if (entry->d_name[0] != '.')
			files[i++] = ft_strdup(entry->d_name);
	files[i] = NULL;
	closedir(dir);
	return (files);
}

/*
 * Função: has_wildcard
 * -------------------------
 * Verifica se a string do comando contém o caractere '*'.
 *
 * Retorna: 1 se encontrar, 0 caso contrário.
 */
int	has_wildcard(const char *cmd)
{
	int	i = 0;

	if (!cmd)
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '*')
			return (1);
		i++;
	}
	return (0);
}
