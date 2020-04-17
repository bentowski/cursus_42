
CC=gcc
CFLAGS=-Wall -Wextra -Werror
FLAGS= -L./libft -lft.a
SRC= $(wildcard *.c)
OBJ= $(SRC: .c=.o)
NAME=libftprintf.a


$(NAME): $(SRC) ft_printf.h

	$(CC) $(CFLAGS) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

# %.o: %.c
# 		$(CC) -o $@ -c $< $(CFLAGS)

all: $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
