NAME = miniRT
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	@cp ./libft/libft.a libft.a
	chmod 555 ./mlx/configure
	$(MAKE) -C ./mlx
	@cp ./mlx/libmlx.a libmlx.a
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean
	rm -rf *.o

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -rf ./mlx/libmlx.a
	rm -rf $(NAME)

re: fclean all
