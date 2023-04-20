/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:37:25 by oroy              #+#    #+#             */
/*   Updated: 2023/04/19 21:35:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_err(int arg_rtn, int nbr)
{
	if (arg_rtn == -1)
		return (-1);
	else
		return (nbr + arg_rtn);
}

static int	write_arg(char c, void *arg)
{
	int	nbr;

	nbr = 0;
	if (c == 'c')
		nbr = ft_putchar_rtn_fd((char)arg, 1);
	else if (c == 's')
	{
		if (!arg)
			return (ft_putstr_rtn_fd("(null)", 1));
		nbr = ft_putstr_rtn_fd((char *)arg, 1);
	}
	else if (c == 'p')
		nbr = ft_putptr_fd((unsigned long)arg, c, 1);
	else if (c == 'd' || c == 'i')
		nbr = ft_putint_fd((int)arg, 1);
	else if (c == 'u')
		nbr = ft_putuint_fd((unsigned int)arg, 1);
	else if (c == 'x' || c == 'X')
		nbr = ft_puthex_fd((unsigned int)arg, c, 1);
	return (nbr);
}

// static void add_flag(char *flags, char c)
// {
// 	if (c == '-')
// 		flags[0] = 1;
// 	else if (c == '0')
// 		flags[1] = 1;
// 	else if (c == '.')
// 		flags[2] = 1;
// 	else if (c == '#')
// 		flags[3] = 1;
// 	else if (c == ' ')
// 		flags[4] = 1;
// 	else if (c == '+')
// 		flags[5] = 1;
// }

int	ft_printf(const char *s, ...)
{
	va_list	valist;
	size_t	i;
	int		nbr;

	if (!s)
		return (0);
	i = 0;
	nbr = 0;
	va_start(valist, s);
	while (s[i] && nbr > -1)
	{
		if (s[i] == '%')
		{
			if (s[++i] == '%')
				nbr = check_err(ft_putchar_rtn_fd('%', 1), nbr);
			else
				nbr = check_err(write_arg(s[i], va_arg(valist, void *)), nbr);
		}
		else
			nbr = check_err(ft_putchar_rtn_fd(s[i], 1), nbr);
		i++;
	}
	va_end(valist);
	return (nbr);
}

// int	main(void)
// {
// 	char	*p;
// 	int		i;

// 	p = ft_calloc (2, sizeof(char));
// 	p[0] = 'A';
// 	p[1] = '\0';

// 	i = printf ("<%c>", '1');
// 	printf ("| %i\n", i);
// 	i = printf ("<%s>", "scooby");
// 	printf ("| %i\n", i);
// 	i = printf ("< NULL %s NULL >", NULL);
// 	printf ("| %i\n", i);
// 	i = printf ("<%p>", (void *)0);
// 	printf ("| %i\n", i);
// 	i = printf ("<%d>", 15);
// 	printf ("| %i\n", i);
// 	i = printf ("<%i>", -21);
// 	printf ("| %i\n", i);
// 	i = printf ("<%u>", -21);
// 	printf ("| %i\n", i);
// 	i = printf ("<%x>", -50);
// 	printf ("| %i\n", i);
// 	i = printf ("<%x %x %x %x>", -500, 500, INT_MAX, INT_MIN);
// 	printf ("| %i\n", i);
// 	i = printf ("<%X>", 500);
// 	printf ("| %i\n", i);
// 	i = printf ("<%%>");
// 	printf ("| %i\n", i);
// 	i = printf ("<%p %c YOYO123456 %% %% %s>", p, 'd', "Comment ca va ?");
// 	printf ("| %i\n", i);
// 	i = ft_printf ("<%c>", '1');
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%s>", "scooby");
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("< NULL %s NULL >", NULL);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%p>", (void *)0);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%d>", 15);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%i>", -21);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%u>", -21);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%x>", -50);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%x %x %x %x>", -500, 500, INT_MAX, INT_MIN);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%X>", 500);
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%%>");
// 	ft_printf ("| %i\n", i);
// 	i = ft_printf ("<%p %c YOYO123456 %% %% %s>", p, 'd', "Comment ca va ?");
// 	ft_printf ("| %i\n", i);
// 	// printf ("<%-10d>\n", 500);
// 	// printf ("%.10x\n", 500000);
// 	// printf ("<%09d>\n", 500);
// 	// ft_printf ("<%-10d>\n", 500);
// 	// ft_printf ("%.10x\n", 500000);
// 	// ft_printf ("<%09d>\n", 500);
// 	return (0);
// }
