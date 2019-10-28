# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 15:24:00 by bbaudry           #+#    #+#              #
#    Updated: 2019/10/26 15:24:03 by bbaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_strjoin.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_split.c \
				ft_calloc.c

OBJECTS = ft_atoi.o \
				ft_bzero.o \
				ft_isalnum.o \
				ft_isalpha.o \
				ft_isascii.o \
				ft_isdigit.o \
				ft_isprint.o \
				ft_itoa.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_memset.o \
				ft_putchar_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_putstr_fd.o \
				ft_strchr.o \
				ft_strdup.o \
				ft_strlcat.o \
				ft_strlcpy.o \
				ft_strlen.o \
				ft_strncmp.o \
				ft_strnstr.o \
				ft_strrchr.o \
				ft_strtrim.o \
				ft_strjoin.c \
				ft_substr.o \
				ft_tolower.o \
				ft_toupper.o \
				ft_split.o \
				ft_calloc.o

INCLUDES = ./

$(NAME): $(SRCS) libft.h

	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)


all: $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
