# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 20:20:29 by oroy              #+#    #+#              #
#    Updated: 2024/12/08 23:13:19 by olivierroy       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft/

SRC =	ft_printf.c \
		ft_printf_types.c \
		$(LIBFT_DIR)ft_abs.c \
		$(LIBFT_DIR)ft_putchar_fd.c \
		$(LIBFT_DIR)ft_putstr_fd.c \
		$(LIBFT_DIR)ft_strlen.c \

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
