/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:51:59 by oroy              #+#    #+#             */
/*   Updated: 2023/04/18 16:23:30 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	final_value;
	int	write_rtn;
	int	div;

	div = 1;
	write_rtn = 0;
	final_value = 0;
	while (n / div >= 10)
		div *= 10;
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
