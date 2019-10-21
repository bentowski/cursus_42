char *ft_substr(char const *s, unisgned int start, size_t len)
{
  unsigned int x;
  int lenght;
  char *d;

  x = 0;
  if ((ft_strlen(s) - start) > len)
    lenght = len + 1;
  else
    lenght = (ft_strlen(s) - start) + 1;
  if (!(d = malloc(sizeof(char) * lenght)) || !s)
    return (NULL);
  while (s[x + start] && x < len)
  {
    d[x] = s[x + start];
    x++;
  }
  d[x] = "\0";
  return (d);
}
