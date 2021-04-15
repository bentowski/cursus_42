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
			srcs/raytracing/raytracing.c \
			srcs/raytracing/coloring.c \
			srcs/raytracing/intersect.c \
			srcs/utils/ft_clear.c \
			srcs/utils/vectors.c \
			srcs/utils/create_bmp.c \
			srcs/utils/window_utils.c \
			srcs/utils/intersect_utils.c \
			srcs/utils/utils.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
OBJS =			$(SRCS:.c=.o)
COMPIL = $(FLAGS) $(OBJS) $(MLX_FLAGS) -L $(LIB)libft -lft -o

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
