/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:51:59 by oroy              #+#    #+#             */
/*   Updated: 2023/04/19 21:35:13 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_multiple(int n)
{
	int	div;

	div = 1;
	while (n / div <= -10 || n / div >= 10)
		div *= 10;
	return (div);
}

int	ft_putint_fd(long n, int fd)
{
	int	final_value;
	int	putchar_rtn;
	int	div;

	putchar_rtn = 0;
	final_value = 0;
	div = get_multiple(n);
	if (n < 0)
	{
		final_value = ft_putchar_rtn_fd('-', fd);
		if (final_value == -1)
			return (-1);
		n = -n;
	}
	while (div != 0)
	{
		putchar_rtn = ft_putchar_rtn_fd(n / div + 48, fd);
		if (putchar_rtn == -1)
			return (-1);
		final_value += putchar_rtn;
		n %= div;
		div /= 10;
	}
	return (final_value);
}

// int	ft_putint_fd(long n, int fd)
// {
// 	int	putchar_rtn;
// 	int	putint_rtn;

// 	putint_rtn = 0;
// 	putchar_rtn = 0;
// 	if (n < 0)
// 	{
// 		putchar_rtn = ft_putchar_rtn_fd('-', fd);
// 		if (putchar_rtn == -1)
// 			return (-1);
// 		n = -n;
// 	}
// 	if (n / 10 != 0)
// 	{
// 		putint_rtn = ft_putint_fd(n / 10, fd);
// 		if (putint_rtn == -1)
// 			return (-1);
// 	}
// 	putchar_rtn += ft_putchar_rtn_fd(n % 10 + 48, fd);
// 	if (putchar_rtn <= 0)
// 		return (-1);
// 	return (putint_rtn + putchar_rtn);
// }
