/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:51:59 by oroy              #+#    #+#             */
/*   Updated: 2023/04/18 17:19:20 by oroy             ###   ########.fr       */
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
	int	write_rtn;
	int	div;

	write_rtn = 0;
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
		write_rtn = ft_putchar_rtn_fd(n / div + 48, fd);
		if (write_rtn == -1)
			return (-1);
		final_value += write_rtn;
		n %= div;
		div /= 10;
	}
	return (final_value);
}
