/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:33:46 by oroy              #+#    #+#             */
/*   Updated: 2023/04/18 18:55:03 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

// typedef struct s_list
// {
// 	char	minus;
// 	char	zero;
// 	char	dot;
// 	char	hash;
// 	char	space;
// 	char	plus;
// }	t_list;

int	ft_printf(const char *s, ...);

#endif
