NAME		= a.out
SRCS    =	main.c \
					includes/get_next_line/get_next_line.c \
					includes/get_next_line/get_next_line_utils.c \
					srcs/raytracing.c \
					srcs/coloring.c \
					srcs/intersect/intersect_objects.c \
					srcs/parsing/parse.c \
					srcs/parsing/parse_forms.c \
					srcs/parsing/parse_forms_utils.c \
					srcs/parsing/parse_utils.c \
					srcs/parsing/parse_basic.c \
					srcs/utils/ft_clear.c \
					srcs/utils/utils.c

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
