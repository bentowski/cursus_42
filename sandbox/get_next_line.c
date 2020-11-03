int get_next_line(int fd, char **line)
{
  char *buffer;
  static char *saved;
  int i;
  int ret;

  i = 0;
  if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
    return (-1);
  while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
  {
    strjoin(*line, buffer, &i);
  }
  if (ret = -1)
    return (-1);
  if (ret = 0)
    return (0);
  // buffer = "tes \n et"
  while (buffer[i] != '\n')
  {
    i++;
  }
  *saved = buffer[i + 1];
  return (1);
}
