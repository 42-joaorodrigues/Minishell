/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:13:03 by joao-alm          #+#    #+#             */
/*   Updated: 2025/05/07 18:13:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_INT_H
#define COMMAND_INT_H

#include "command.h"
#include "token.h"

t_command	*ft_create_command(t_token **token);

#endif //COMMAND_INT_H
