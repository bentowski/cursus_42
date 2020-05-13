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

NAME    	= libftprintf.a

SRCDIR    = ./

SRCS    	=	$(addprefix $(SRCDIR), *.c libft/ft_putnbr_fd.c \
							libft/ft_putchar_fd.c libft/ft_strlen.c)

OBJ       = $(SRCS:.c=.o)

CC        = gcc

CFLAGS    = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME): $(OBJ) ft_printf.h
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJ}

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
