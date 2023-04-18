# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 20:20:29 by oroy              #+#    #+#              #
#    Updated: 2023/04/18 16:00:46 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		libft/ft_calloc.c \
		libft/ft_putchar_rtn_fd.c \
		libft/ft_puthex_fd.c \
		libft/ft_putint_fd.c \
		libft/ft_putstr_rtn_fd.c \
		libft/ft_putuint_fd.c \
		libft/ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
