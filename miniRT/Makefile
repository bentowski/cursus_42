NAME    = a.out
SRCS    =	main.c \
					parse.c \
					parse_forms.c \
					parse_forms_utils.c \
					parse_basic.c \
					parse_coordonnees.c \
					includes/get_next_line/get_next_line.c \
					includes/get_next_line/get_next_line_utils.c

SRCDIR    = ./
CC        = gcc -D BUFFER_SIZE=4
FLAGS    	= -Wall -Wextra -Werror
LIB				=	-L. -lmlx

$(NAME):
	@$(CC) $(SRCS) $(LIB)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:         clean
	@rm -f $(NAME)

re:             fclean all

.PHONY:         all clean fclean re