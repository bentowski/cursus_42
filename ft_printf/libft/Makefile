# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 15:24:00 by bbaudry           #+#    #+#              #
#    Updated: 2019/10/26 15:24:03 by bbaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS    	=	$(addprefix $(SRCDIR), *.c)


SRCS_B= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ= $(SRCS:.c=.o)
OBJB = $(SRCS_B:.c=.o)
INCLUDES=./
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(SRCS) libft.h

	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(NAME)

	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS_B)
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)


clean:
	@/bin/rm -f $(OBJ) $(OBJB)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
