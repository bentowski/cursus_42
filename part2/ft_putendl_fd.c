void ft_putendl_fd(char *s, int fd)
{
  while (*s)
  {
    ft_putchar_fd(*s, fd);
    s++;
  }
  write(fd, "\n", 1);
}
