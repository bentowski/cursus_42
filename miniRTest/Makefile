NAME		= a.out
SRCS    =	test.c
SRCDIR    = ./
CC        = gcc -D BUFFER_SIZE=4
FLAGS    	= -Wall -Wextra -Werror
LIB				=	-L. -lmlx

$(NAME):	$(SRCS) minirt.h
	@$(CC) $(SRCS) $(LIB)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:         clean
	@rm -f $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
