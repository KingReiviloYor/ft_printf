/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:14:57 by oroy              #+#    #+#             */
/*   Updated: 2023/04/19 21:35:27 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	convert_char(unsigned int n, char c)
{
	if (n < 10)
		return (n + 48);
	else
	{
		if (c == 'X')
			return (n + 55);
		else
			return (n + 87);
	}
}

int	ft_puthex_fd(unsigned long n, char c, int fd)
{
	int	putchar_rtn;
	int	puthex_rtn;

	puthex_rtn = 0;
	if (n / 16 != 0)
	{
		puthex_rtn = ft_puthex_fd(n / 16, c, fd);
		if (puthex_rtn == -1)
			return (-1);
	}
	putchar_rtn = ft_putchar_rtn_fd(convert_char(n % 16, c), fd);
	if (putchar_rtn == -1)
		return (-1);
	return (puthex_rtn + putchar_rtn);
}
