char  *ft_strtrim(char const *s1, char const *set)
{
  int start;
  int end;
  int x;
  int y;
  char *d;

  x = 0;
  y = 0;
  start = ft_currentway(s1, set, x, y);
  if (start == ft_strlen(s1))
    return (NULL);
  x = ft_strlen(s1);
  y = x;
  end = ft_strlen(s1) - ft_reverseway(s1, set, x, y);
  if (!(d = (char *)malloc(end - start + 2)))
    return (NULL);
  while (start < end)
  {
    d[start - end]
  }
}

int ft_currentway(char const *s1, char const *set, int x, int y)
{
  int start;

  start = 0;
  while (s1[y])
  {
    x = 0;
    while (set[x])
    {
      if (set[x] == s1[y])
        start++;
      x++;
    }
    y++;
  }
  return (start);
}

 int ft_reverseway(char const *s1, char const *set, int x, int y)
 {
   int end;
   int s;

   end = 0;
   while(s1[x])
   {
     s = 0;
     while (set[s])
     {
       if (set[s] == s1[x])
          end++;
        s++;
     }
     x--;
   }
   return (end);
 }
