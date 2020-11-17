NAME    = a.out
SRCS    =	main.c \
					parsing/parse.c \
					parsing/parse_forms.c \
					parsing/parse_forms_utils.c \
					parsing/parse_basic.c \
					parsing/parse_utils.c \
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
