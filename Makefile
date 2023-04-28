# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 20:20:29 by oroy              #+#    #+#              #
#    Updated: 2023/04/25 12:19:10 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft/

SRC =	ft_printf.c \
		$(LIBFT_DIR)ft_add.c \
		$(LIBFT_DIR)ft_putchar_rtn_fd.c \
		$(LIBFT_DIR)ft_puthex_rtn_fd.c \
		$(LIBFT_DIR)ft_putnbr_rtn_fd.c \
		$(LIBFT_DIR)ft_putstr_rtn_fd.c \
		$(LIBFT_DIR)ft_strlen.c

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
