/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 18:30:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

// Colors
# define PINK "\033[38;5;211m"
# define YELLOW "\033[38;5;228m"
# define GREEN "\033[38;5;121m"
# define PURPLE "\033[38;5;141m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

// Debug
// # define PINK ""
// # define RESET ""
// # define YELLOW ""
// # define GREEN ""
// # define PURPLE ""
// # define BOLD ""

// Codes
# define SUCCESS 0
# define ERROR 1
# define E_MEM_ALLOC 10
# define E_SYNTAX 11
# define E_QUOTES 12

int	ft_print_error(int errno);

#endif // UTIL_H
