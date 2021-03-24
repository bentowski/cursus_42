SHELL :=		/bin/bash

CC =			clang -D BUFFER_SIZE=4
FLAGS =			-Wall -Wextra -Werror -g
RM =			rm -rf
DIR_HEADERS =	./includes/
DIR_SRCS =		./
MLX_DIR = 		./
MLX_HEADER = 	/usr/local/include/
MLX_LIB = 		/usr/local/lib/
MLX_FLAGS	=	-lmlx
MACOS_FLAGS =	-framework OpenGL -framework AppKit
LINUX_FLAGS =	-lXext -lX11 -lm
LIBMLX =		libmlx.a
LIBFT =			libft.a
FSAN =			-fsanitize=address
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
			srcs/utils/saving.c \
			srcs/utils/utils.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
OBJS =			$(SRCS:.c=.o)
NAME =			miniRT
UNAME := 		$(shell uname)
COMPIL = $(FLAGS)
CP_MLX_H =		@cp $(MLX_DIR)/*.h $(MLX_HEADER)
CP_MLX_LIB =	@cp $(MLX_DIR)/$(LIBMLX) $(MLX_LIB)

CP_MLX_H += && echo "Copying mlx headers"
CP_MLX_LIB += && echo "Copying mlx library"
MLX_DIR = ./mlx_linux
MLX_FLAGS = -Lmlx -lmlx -L$(MLX_LIB) -Imlx_linux $(LINUX_FLAGS)
FLAGS += -I$(DIR_HEADERS) -I$(MLX_HEADER) -Imlx_linux
OS = -D LINUX

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(MAKE) -C ./libft
				@cp ./libft/libft.a libft.a
				@chmod 555 ./mlx/configure
				@$(MAKE) -C ./mlx
				@cp ./mlx/libmlx.a libmlx.a
				@$(CC) $(COMPIL) $(OS) $(RES) $(OBJS) $(MLX_FLAGS) -L $(LIB)libft -lft -o $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) $(OS) $(RES) -c $< -o $@
				@echo "Compiled "$<" successfully!"

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean
	rm -rf *.o srcs/*.o srcs/*/*.o

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -rf ./mlx/libmlx.a
	rm -rf libft.a libmlx.a
	rm -rf $(NAME)

re: fclean all


# re: fclean all
# NAME		= a.out
# SRC =	main.c
# # SRC    =	includes/get_next_line/get_next_line.c \
# # 					includes/get_next_line/get_next_line_utils.c
# 					# srcs/raytracing.c \
# 					# srcs/coloring.c \
# 					# srcs/intersect/intersect_objects.c \
# 					# srcs/parsing/parse.c \
# 					# srcs/parsing/parse_forms.c \
# 					# srcs/parsing/parse_forms_utils.c \
# 					# srcs/parsing/parse_utils.c \
# 					# srcs/parsing/parse_basic.c \
# 					# srcs/utils/ft_clear.c \
# 					# srcs/utils/utils.c
#
# SRCDIR    = ./
# SRCS			=	$(addprefix $(DIR_SRCS), $(SRC))
# OBJS			= $(SRCS:.c=.o)
# CC        = gcc -D BUFFER_SIZE=4
# FLAGS    	= -Wall -Wextra -Werror
# LIB				=	-L. -lmlx
#
# $(NAME):	$(SRCS)
# 	$(MAKE) -C ./libft bonus
# 	@cp ./libft/libft.a libft.a && cp ./libft/libft.h ./libft.h
# 	@cp ./includes/mlx/*.h /usr/local/include/
# 	@$(MAKE) CFLAGS="-Wall -Werror -Wextra -I"-C ./includes/mlx/
# 	@cp ./includes/mlx/libmlx.a /usr/local/lib/
# 	$(CC) $(FLAGS) $(OBJS) -lmlx -L libft -lft -o $(NAME)
#
#
#
# # $(NAME) :		$(OBJS)
# # 				@$(MAKE) -C ./libft bonus
# # 				@cp ./libft/$(LIBFT) $(LIBFT) && cp ./libft/libft.h $(DIR_HEADERS)/libft.h
# # 				$(CP_MLX_H)
# # 				@$(MAKE) CFLAGS="-w" -C $(MLX_DIR)
# # 				$(CP_MLX_LIB)
# # 				@$(CC) $(COMPIL) $(OS) $(RES) $(OBJS) $(MLX_FLAGS) -L $(LIB)libft -lft -o $(NAME)
#
#
# all:	$(NAME)
#
# clean:
# 	@rm -f $(OBJ)
#
# fclean:         clean
# 	@rm -f $(NAME)
#
# re:             fclean all
#
# .PHONY:         all clean fclean re
