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

# ft_printf.c \
# 						ft_chars.c \
# 						ft_general_utils.c \
# 						ft_numeric_utils.c \
# 						ft_numeric.c
					# libft/ft_putnbr_fd.c \
					# libft/ft_putchar_fd.c \
					# libft/ft_strlen.c

OBJ       = $(SRCS:.c=.o)

CC        = gcc

CFLAGS    = -Wall -Werror -Wextra

LIB				= -L${LIBSRC} -lft

LIB_MAKE	= ${MAKE} -C ${LIBSRC}

# $(SRCDIR)%.o:    $(SRCDIR)%.c
# 	$(CC) $(FLAGS) -o $@ -c $<

all:	$(NAME)

$(NAME): $(OBJ) libmake
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

# test:	${NAME}
# 	gcc ${NAME} main.c
# 	./a.out
# .PHONY:    all clean fclean re
