# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#              #
#    Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
SRCS    =	ft_printf.c \
					ft_numeric.c \
					ft_numeric_utils.c \
					ft_chars.c \
					ft_general_utils.c \
					libft/ft_strlen.c \
					libft/ft_putchar_fd.c \
					libft/ft_putnbr_fd.c

SRCDIR    = ./
CC        = gcc
FLAGS    = -Wall -Wextra -Werror
OBJ        = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

$(SRCDIR)%.o:    $(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME):         $(OBJ)
	ar rc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:         clean
	rm -f $(NAME)

re:             fclean all

# test:	${NAME}
# 	gcc ${NAME} main.c
# 	./a.out
.PHONY:            all clean fclean re
