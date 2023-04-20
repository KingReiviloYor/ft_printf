/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:14:57 by oroy              #+#    #+#             */
/*   Updated: 2023/04/19 21:35:39 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long n, char c, int fd)
{
	int	rtn_value;

	rtn_value = ft_putstr_rtn_fd("0x", 1);
	if (rtn_value > -1)
	{
		rtn_value += ft_puthex_fd(n, c, fd);
		if (rtn_value < 2)
			rtn_value = -1;
	}
	return (rtn_value);
}
