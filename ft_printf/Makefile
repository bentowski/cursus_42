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

LIBSRC	= libft/

SRCS    	=	$(addprefix $(SRCDIR), *.c)

OBJ       = $(SRCS:.c=.o)

CC        = gcc

CFLAGS    = -Wall -Werror -Wextra

LIB				= -L${LIBSRC} -lft

LIB_MAKE	= ${MAKE} -C ${LIBSRC}

all:	$(NAME)

$(NAME): $(OBJ) libmake ft_printf.h
	${CC} ${CFLAGS} ${LIB} -c ${SRCS}
	ar rc ${NAME} ${OBJ}

libmake:
	${LIB_MAKE}

clean:
	rm -f $(OBJ)
	${LIB_MAKE} clean

fclean:	clean
	rm -f $(NAME)
	${LIB_MAKE} fclean

re:	fclean all
