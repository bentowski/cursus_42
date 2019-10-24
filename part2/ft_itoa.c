char *ft_itoa(int n)
{
  int i;

  i = 0;
  while ((n / 10) != 0)
  {
    n = n / 10;
    i++;
  }
  if (!(tab = (char *)malloc(i + 1)))
    return (NULL);
  i = 0;
  while (n != 0)
  {
    tab[i] = n % 10;
    n = n / 10;
    i++;
  }
  tab[i] = '\0';
}
