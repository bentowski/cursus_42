NAME=libftprintf.a

SRCS= ft_printf.c ft_strlen.c ft_putnbr_fd.c ft_putchar_fd.c

OBJ= $(SRCS:.c=.o)
INCLUDES=./
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h

	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)


clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
