# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 19:33:02 by ygeslin           #+#    #+#              #
#    Updated: 2020/02/23 15:48:53 by ygeslin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
SRCS    =	ft_printf.c \
					ft_d.c \
					ft_setc.c \
					ft_u.c \
					ft_xetp.c \
					ft_utils.c \
					libft/ft_putnbr_fd.c \
					libft/ft_putchar_fd.c \
					libft/ft_strlen.c

SRCDIR    = ./
CC        = gcc
FLAGS    = -Wall
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

test:	${NAME}
	gcc ${NAME} main.c
	./a.out
.PHONY:            all clean fclean re
