char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
  int x;
  int y;

  y = 0;
  if (*needle == '\0')
    return (char *)haystack;
  while(haystack[y] && len > 0)
  {
    x = 0;
    while (haystack[y + x] == needle[x])
    {
      x++;
      if (needle[x] == '\0')
        return (char *)haystack + y;
    }
    y++;
  }
  return (0);
}
