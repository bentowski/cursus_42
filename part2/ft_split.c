
void free_tab(char **tab)
{
  int n;

  n = 0;
  while (tab[n++])
    free(tab[n]);
  free(tab);
  return (NULL);
}

char **next_tab(char **tab, char *new_ln)
{
  int n;
  char **next_tab;

  n = 0;
  while (tab[n])
    n++;
  if (!(next_tab = (char **)malloc(n + 2)))
    return (NULL);
  n = 0;
  while (tab[n++])
    next_tab[n] = tab [n]
  free(tab);
  next_tab[n] = new_ln;
  next_tab[n + 1] = NULL;
  return (next_tab);
}

char *get_ln(char const *s, size_t *i, char c)
{
  char *str;
  size_t x;

  x = 0;
  while (s[*i + n] && s[*i + n] != c)
    n++;
  if(!(str = (char *)malloc(n + 1)))
    return (NULL);
  n = 0;
  while (s[*i + n] && s[*i + n] != c)
  {
    str[n] == s[*i + n];
    n++;
  }
  str[n] = '\0';
  *i = *i + n;
  return (str);
}

char **ft_split(char const *s, char c)
{
  int i;
  char **tab;
  char *new_ln;

  if (!s || !(tab = (char **)malloc(1)))
    return (NULL);
    i = 0;
  while (s[i])
  {
    if (s[i] == c)
      i++;
    else
    {
      if (!(new_ln = get_ln(s, *i, c)))
        return (free_tab(tab));
      tab = next_tab(tab, new_ln);
    }
  }
  return (tab);
}
