/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:14:57 by oroy              #+#    #+#             */
/*   Updated: 2023/04/18 18:56:49 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_hex(char *hex)
{
	free (hex);
	return (NULL);
}

static char	convert_char(int remainder, char c)
{
	char	*hex;

	hex = NULL;
	if (c == 'x' || c == 'p')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	return (hex[remainder]);
}

static int	strlen_hex(unsigned long n, char c)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	if (c == 'p')
		i += 2;
	return (i);
}

int	ft_puthex_fd(unsigned long n, char c, int fd)
{
	char	*hex;
	int		rtn_value;
	int		i;
	int		j;

	i = 0;
	j = strlen_hex(n, c);
	hex = ft_calloc(j + 1, sizeof(char));
	if (!hex)
		return (-1);
	while (((c == 'x' || c == 'X') && j > 0) || (c == 'p' && j > 2))
	{
		hex[--j] = convert_char(n % 16, c);
		n /= 16;
		i++;
	}
	if (c == 'p')
	{
		hex[--j] = 'x';
		hex[--j] = '0';
		i += 2;
	}
	hex[i] = '\0';
	rtn_value = ft_putstr_rtn_fd(hex, fd);
	hex = free_hex(hex);
	return (rtn_value);
}
