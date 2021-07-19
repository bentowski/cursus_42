SHELL :=		/bin/bash

NAME =			pipex
CC =			clang
FLAGS =			-Wall -Wextra -Werror -g
RM =			rm -rf
DIR_SRCS =		./
LIBFT =			libft.a
SRC =	main.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
OBJS =			$(SRCS:.c=.o)
COMPIL = $(FLAGS) $(OBJS) -L libft -lft -o

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(MAKE) -C ./libft
				@cp ./libft/libft.a libft.a
				@$(CC) $(COMPIL) $(NAME)

%.o: %.c
				@$(CC) -c $< -o $@
				@echo "Compiled "$<" successfully!"

clean:
	$(MAKE) -C ./libft clean
	$(RM) *.o */*.o

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all
