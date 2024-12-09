/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:33:46 by oroy              #+#    #+#             */
/*   Updated: 2024/12/08 23:06:16 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	print_s(char *s, int fd);
int	print_int(int i, int fd);
int	print_uint(unsigned int u, int fd);
int	print_hex(unsigned long u, char c, int fd);
int	print_p(unsigned long p, int fd);

#endif
