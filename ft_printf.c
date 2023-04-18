/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:37:25 by oroy              #+#    #+#             */
/*   Updated: 2023/04/18 18:58:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	exception_handler(char c)
// {
// 	int	nbr;

// 	nbr = 0;
// 	if (c == 's')
// 		nbr = ft_putstr_rtn_fd("(null)", 1);
// 	else if (c == 'p')
// 		nbr = ft_putstr_rtn_fd("0x0", 1);
// 	return (nbr);
// }

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
		nbr = ft_puthex_fd((unsigned long)arg, c, 1);
	else if (c == 'd' || c == 'i')
		nbr = ft_putint_fd((int)arg, 1);
	else if (c == 'u')
		nbr = ft_putuint_fd((unsigned int)arg, 1);
	else if (c == 'x' || c == 'X')
		nbr = ft_puthex_fd((unsigned int)arg, c, 1);
	else if (c == '%')
		nbr = ft_putchar_rtn_fd('%', 1);
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
	int		arg_rtn;
	int		nbr;

	if (!s)
		return (0);
	i = 0;
	nbr = 0;
	va_start(valist, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			// while (!ft_strchr("cspdiuxX%", s[i]))
			// {
			// 	if (ft_strchr("-0.", s[i]))
			// 		add_flag(flags, s[i]);
			// 	i++;
			// }
			// if (s[i])
			if (s[i] == '%')
				arg_rtn = ft_putchar_rtn_fd('%', 1);
			else
				arg_rtn = write_arg(s[i], va_arg(valist, void *));
			if (arg_rtn == -1)
			{
				nbr = -1;
				break ;
			}
			nbr += arg_rtn;
		}
		else
		{
			arg_rtn = ft_putchar_rtn_fd(s[i], 1);
			if (arg_rtn == -1)
			{
				nbr = -1;
				break ;
			}
			nbr += arg_rtn;
		}
		i++;
	}
	va_end(valist);
	return (nbr);
}

// int	main(void)
// {
// 	char	*p;

// 	p = ft_calloc (2, sizeof(char));
// 	p[0] = 'A';
// 	p[1] = '\0';
	
// 	printf ("<%c>\n", '1');
// 	printf ("<%s>\n", "scooby");
// 	printf ("< NULL %s NULL >\n", NULL);
// 	printf ("<%p>\n", (void *)0);
// 	printf ("<%d>\n", 15);
// 	printf ("<%i>\n", -21);
// 	printf ("<%u>\n", -21);
// 	printf ("<%x>\n", -50);
// 	printf ("<%x %x %x %x>\n", -500, 500, INT_MAX, INT_MIN);
// 	printf ("<%X>\n", 500);
// 	printf ("<%%>\n");
// 	printf ("<%p %c YOYO123456 %% %% %s>", p, 'd', "Comment ca va ?");
// 	printf ("\n");
// 	ft_printf ("<%c>\n", '1');
// 	ft_printf ("<%s>\n", "scooby");
// 	ft_printf ("< NULL %s NULL >\n", NULL);
// 	ft_printf ("<%p>\n", (void *)0);
// 	ft_printf ("<%d>\n", 15);
// 	ft_printf ("<%i>\n", -21);
// 	ft_printf ("<%u>\n", -21);
// 	ft_printf ("<%x>\n", -50);
// 	ft_printf ("<%x %x %x %x>\n", -500, 500, INT_MAX, INT_MIN);
// 	ft_printf ("<%X>\n", 500);
// 	ft_printf ("<%%>\n");
// 	ft_printf ("<%p %c YOYO123456 %% %% %s>", p, 'd', "Comment ca va ?");
// 	ft_printf ("\n");
// 	// printf ("<%-10d>\n", 500);
// 	// printf ("%.10x\n", 500000);
// 	// printf ("<%09d>\n", 500);
// 	// ft_printf ("<%-10d>\n", 500);
// 	// ft_printf ("%.10x\n", 500000);
// 	// ft_printf ("<%09d>\n", 500);
// 	return (0);
// }
