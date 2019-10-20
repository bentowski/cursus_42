
char *strrchr(const char *s, int c)
{
  int len;

  len = ft_strlen(s);
  while (len > 0)
  {
    if (s[len] == c)
      return ((char *)s + len);
    len--;
  }
  return (NULL);
}
