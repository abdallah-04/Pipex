# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/31 10:55:52 by amufleh           #+#    #+#              #
#    Updated: 2025/09/02 09:41:05 by amufleh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c print_char.c print_str.c print_int.c len.c print_hex.c print_ptr.c print_unsigned.c


CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
$(LIBFT):
	make -C libft
clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean $(NAME)


.PHONY : all clean fclean re

