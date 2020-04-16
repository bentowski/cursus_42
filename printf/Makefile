

CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC= $(wildcard *.c)
OBJ= $(SRC: .c=.o)
NAME=libftprintf.a


$(NAME):  $(OBJ)
		$(CC) -o $@ $^ -L./libft -lft $(CFLAGS)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

main.o: ft_printf.h

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		rm -rf *.o

fclean:
		rm -rf ft_printf

re: fclean ft_printf
