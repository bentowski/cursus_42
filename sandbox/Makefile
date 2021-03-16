NAME=testeur

SRCDIR = ./

SRCS= main.c

OBJ        = $(addprefix $(SRCDIR), $(SRCS:.c=.o))
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

$(SRCDIR)%.o:    $(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SRCS) bidon.h

	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(NAME)

	$(CC) $(CFLAGS) -c $(SRCS_B)
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)


clean:
	@/bin/rm -f $(OBJ) $(OBJB)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

# NAME = testeur
# CC = clang
# FLAGS = -Wall -Wextra -Werror -g
# RM = rm -rf
# DIR_HEADERS = ./includes/
# DIR_SRCS = ./
# MLX_DIR = ./
# MLX_HEADER = /usr/local/include/
# MLX_LIB = /usr/local/lib/
# MLX_FLAGS = -Lmlx
# LINUX_FLAGS = -lXext -lX11 -lm
# LIBMLX = libmlx.a
# LIBFT = libft.a
#
# SRC = main.c
#
# SRCS = $(addprefix $(DIR_SRCS), $(SRC))
#
# OBJS = $(SRC:.c=.o)
#
# CP_MLX_H = @cp $(MLX_DIR)/*.h $(MLX_HEADER)
# CP_MLX_LIB = @cp $(MLX_DIR)/$(LIBMLX) $(MLX_LIB)
#
#
# $(NAME) : $(OBJS)
# 	$(CP_MLX_H)
# 	@$(MAKE) CFLAGS="-Wall -Wextra -Werror -g" -C $(MLX_DIR)
# 	$(CP_MLX_LIB)
# 	@$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -L -o
#
# %.o: %.c
# 				@$(CC) $(FLAGS) -c $< -o $@
# 				@echo "Compiled "$<" successfully!"
