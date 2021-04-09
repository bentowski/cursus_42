#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t count);
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);


#endif
