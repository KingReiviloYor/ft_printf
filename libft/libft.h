/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:32:25 by oroy              #+#    #+#             */
/*   Updated: 2023/04/25 12:54:20 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int		ft_add(int write_rtn, int nbr);
int		ft_putchar_rtn_fd(char c, int fd);
int		ft_puthex_rtn_fd(unsigned long n, char c, int fd);
int		ft_putnbr_rtn_fd(long n, int fd);
int		ft_putstr_rtn_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
