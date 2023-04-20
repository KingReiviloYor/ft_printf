/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:51:59 by oroy              #+#    #+#             */
/*   Updated: 2023/04/19 21:02:03 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_putuint_fd(unsigned int n, int fd)
// {
// 	int	final_value;
// 	int	putchar_rtn;
// 	int	div;

// 	div = 1;
// 	putchar_rtn = 0;
// 	final_value = 0;
// 	while (n / div >= 10)
// 		div *= 10;
// 	while (div != 0)
// 	{
// 		putchar_rtn = ft_putchar_rtn_fd(n / div + 48, fd);
// 		if (putchar_rtn == -1)
// 			return (-1);
// 		final_value += putchar_rtn;
// 		n %= div;
// 		div /= 10;
// 	}
// 	return (final_value);
// }

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	putchar_rtn;
	int	putuint_rtn;

	putuint_rtn = 0;
	if (n / 10 != 0)
	{
		putuint_rtn = ft_putuint_fd(n / 10, fd);
		if (putuint_rtn == -1)
			return (-1);
	}
	putchar_rtn = ft_putchar_rtn_fd(n % 10 + 48, fd);
	if (putchar_rtn == -1)
		return (-1);
	return (putuint_rtn + putchar_rtn);
}
