# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 17:29:15 by bentowsk          #+#    #+#              #
#    Updated: 2021/04/29 17:46:13 by bentowski        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

NAME = checker
CC = clang
FLAGS =			-Wall -Wextra -Werror -g
RM =			rm -rf
LIBFT =			libft.a
SRC =	main.c
OBJS =			$(SRCS:.c=.o)
COMPIL = $(FLAGS) $(OBJS) -L $(LIB)libft -lft -o

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(MAKE) -C ./libft
				@cp ./libft/libft.a libft.a
				@$(CC) $(COMPIL) $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean
	$(RM) *.o srcs/*.o srcs/*/*.o includes/get_next_line/*.o

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) *.bmp
	$(RM) ./mlx/libmlx.a
	$(RM) $(LIBFT) $(LIBMLX)
	$(RM) $(NAME)

re: fclean all
