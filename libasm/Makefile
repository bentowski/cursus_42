NAME    = libasm.a

SRCS    =	ft_write.s \
					ft_read.s \
					ft_strcpy.s \
					ft_strlen.s \
					ft_strcmp.s \
					ft_strdup.s
SRCDIR    = ./
CC        = clang
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
	rm -f *.o

try: re
	$(CC) $(FLAGS) -c main.c
	$(CC) $(FLAGS) main.o $(NAME) -o testeur

fclean:         clean
	rm -f $(NAME)
	rm -f testeur

re:             fclean all

.PHONY:            all clean try fclean re
