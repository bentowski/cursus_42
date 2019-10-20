SRC := \
	srcs/ft_atoi.c \
	srcs/ft_isascii.c \
	srcs/ft_bzero.c \
	srcs/ft_isalpha.c \
	srcs/ft_isalnum.c \
	srcs/ft_isdigit.c \
	srcs/ft_isprint.c \
	srcs/ft_memcpy.c \
	srcs/ft_memccpy.c \
	srcs/ft_strlen.c \
	srcs/ft_memset.c \
	srcs/ft_toupper.c \
	srcs/ft_tolower.c \
	srcs/ft_strncmp.c \
	srcs/ft_memmove.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_strrchr.c \
	srcs/ft_strchr.c \
	srcs/ft_strlcpy.c \
	srcs/ft-strlcat.c \
	srcs/ft-strnstr.c \
	main.c \

OBJS := $(SRC:.c=.o)
GFLAGS := -Wall -Wextra -Werror -I $(HEAD)
HEAD := includes
EXE := libft

all: $(EXE) clean

$(EXE): $(HEAD) $(OBJS)
	gcc $(GFLAGS) -c $(OBJS) -o $(EXE)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(EXE)

re: fclean all
