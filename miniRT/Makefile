# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 00:35:40 by bentowsk          #+#    #+#              #
#    Updated: 2021/05/10 07:04:17 by bentowski        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL :=		/bin/bash

NAME =			miniRT
CC =			clang -D BUFFER_SIZE=4
FLAGS =			-Wall -Wextra -Werror -g
RM =			rm -rf
DIR_SRCS =		./
MLX_LIB = 		/usr/local/lib/
LINUX_FLAGS =	-lXext -lX11 -lm
MLX_FLAGS = -Lmlx -lmlx -L$(MLX_LIB) -Imlx $(LINUX_FLAGS)
LIBMLX =		libmlx.a
LIBFT =			libft.a
SRC =	main.c \
			includes/get_next_line/get_next_line.c \
			includes/get_next_line/get_next_line_utils.c \
			srcs/parsing/parse.c \
			srcs/parsing/parse_forms.c \
			srcs/parsing/parse_forms_utils.c \
			srcs/parsing/parse_utils.c \
			srcs/parsing/parse_basic.c \
			srcs/parsing/parse_basic2.c \
			srcs/raytracing/raytracing.c \
			srcs/raytracing/coloring.c \
			srcs/raytracing/intersect.c \
			srcs/utils/ft_clear.c \
			srcs/utils/vectors.c \
			srcs/utils/create_bmp.c \
			srcs/utils/window_utils.c \
			srcs/utils/intersect_utils.c \
			srcs/utils/utils.c

BONUS_SRC = srcs/bonus/main_bonus.c \
			includes/get_next_line/get_next_line.c \
			includes/get_next_line/get_next_line_utils.c \
			srcs/bonus/parsing_bonus/parse_bonus.c \
			srcs/bonus/parsing_bonus/parse_forms_bonus.c \
			srcs/bonus/parsing_bonus/parse_forms_utils_bonus.c \
			srcs/parsing/parse_utils.c \
			srcs/bonus/parsing_bonus/parse_basic_bonus.c \
			srcs/bonus/parsing_bonus/parse_basic2_bonus.c \
			srcs/bonus/parsing_bonus/parsing_py_bonus.c \
			srcs/bonus/parsing_bonus/parsing_py2_bonus.c \
			srcs/bonus/parsing_bonus/parsing_cube_bonus.c \
			srcs/bonus/raytracing_bonus/raytracing_bonus.c \
			srcs/raytracing/coloring.c \
			srcs/bonus/raytracing_bonus/intersect_bonus.c \
			srcs/bonus/utils_bonus/ft_clear_bonus.c \
			srcs/utils/vectors.c \
			srcs/utils/create_bmp.c \
			srcs/bonus/utils_bonus/window_utils_bonus.c \
			srcs/bonus/utils_bonus/window_utils_mov_bonus.c \
			srcs/utils/intersect_utils.c \
			srcs/utils/utils.c \
			srcs/bonus/utils_bonus/utils_bonus.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
BONUS_SRCS =			$(addprefix $(DIR_SRCS), $(BONUS_SRC))
OBJS =			$(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)
COMPIL = $(FLAGS) $(OBJS) $(MLX_FLAGS) -L $(LIB)libft -lft -o
BONUS_COMPIL = $(FLAGS) $(OBJS_BONUS) $(MLX_FLAGS) -L $(LIB)libft -lft -o

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(MAKE) -C ./libft
				@cp ./libft/libft.a libft.a
				@chmod 555 ./mlx/configure
				@$(MAKE) -C ./mlx
				@cp ./mlx/libmlx.a libmlx.a
				@$(CC) $(COMPIL) $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus: $(OBJS_BONUS)
				@$(MAKE) -C ./libft
				@cp ./libft/libft.a libft.a
				@chmod 555 ./mlx/configure
				@$(MAKE) -C ./mlx
				@cp ./mlx/libmlx.a libmlx.a
				@$(CC) $(BONUS_COMPIL) $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) *.o srcs/*.o srcs/*/*/*.o srcs/*/*.o includes/get_next_line/*.o

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) *.bmp

re: fclean all
