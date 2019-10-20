char  *ft_strdup(const char *s1)
{
  size_t len;
  char *cpy;

  len = ft_strlen(s1) + 1;
  if (!(cpy = malloc(sizeof(char)*len)))
    return (NULL);
  ft_memcpy(cpy, s1, len);
  return (cpy);
}
