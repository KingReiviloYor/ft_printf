/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:53:17 by oroy              #+#    #+#             */
/*   Updated: 2023/04/24 17:56:20 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*p;
	int		i;

	p = NULL;
	i = printf ("<%c>", '1');
	printf ("| %i\n", i);
	i = printf ("<%s>", "scooby");
	printf ("| %i\n", i);
	i = printf ("< NULL %s NULL >", NULL);
	printf ("| %i\n", i);
	i = printf ("<%p>", (void *)-1);
	printf ("| %i\n", i);
	i = printf ("<%ld>", -2147483648);
	printf ("| %i\n", i);
	i = printf ("<%i>", 0x7F);
	printf ("| %i\n", i);
	i = printf ("<%u>", -1);
	printf ("| %i\n", i);
	i = printf ("<%x>", -50);
	printf ("| %i\n", i);
	i = printf ("<%X>", 0xffffffff);
	printf ("| %i\n", i);
	i = printf ("<%%>");
	printf ("| %i\n", i);
	i = printf ("<%p %c YOYO123456 %% %% %s>", p, 'd', "Comment ca va ?");
	printf ("| %i\n", i);
	i = ft_printf ("<%c>", '1');
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%s>", "scooby");
	ft_printf ("| %i\n", i);
	i = ft_printf ("< NULL %s NULL >", NULL);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%p>", (void *)-1);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%d>", -2147483648);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%i>", 0x7F);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%u>", -1);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%x>", -50);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%X>", 0xffffffff);
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%%>");
	ft_printf ("| %i\n", i);
	i = ft_printf ("<%p %c YOYO123456 %% %% %s>", p, 'd', "Comment ca va ?");
	ft_printf ("| %i\n", i);
	return (0);
}
