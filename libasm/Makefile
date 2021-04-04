NAME    = libasm.a

SRCS    =	ft_write.s
SRCDIR    = ./
CC        = gcc
FLAGS    = -Wall -Wextra -Werror
OBJ        = $(addprefix $(SRCDIR), $(SRCS:.s=.o))

$(SRCDIR)%.o: $(SRCDIR)%.s
	nasm -f elf64 $<

$(NAME):         $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:         clean
	rm -f $(NAME)

re:             fclean all

.PHONY:            all clean fclean re
