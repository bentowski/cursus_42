int ft_test(char const c, char const *set)
{
  int i;

  i = 0;
  while(set[i])
  {
    if (c == set[i])
      return (1);
    i++;
  }
  return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
  int i;
  int j;

  i = 0;
  if (!s1)
    return (ft_strdup(s1));
  while(ft_test(s1[i], set))
    i++;
  j = ft_strlen(s1) - 1;
  while (j > i && ft_test(s1[j], set))
    j--;
  return (ft_substr(s1, i, (j - i + 1)));
}
