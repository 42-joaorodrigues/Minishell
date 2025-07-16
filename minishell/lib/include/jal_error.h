/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jal_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:37:17 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/15 17:37:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JAL_ERROR_H
# define JAL_ERROR_H

# define ERROR_PINK "\033[38;5;211m"
# define ERROR_RESET "\033[0m"

# define E_NOMEM 69

int	*ft_exit_code(void);
int	ft_error(const char *err_str, int err_no);

#endif // JAL_ERROR_H
