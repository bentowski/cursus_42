size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
  char *pdst;
  const char *psrc;
  int dstlen;
  int x;

  x = 0;
  pdst = (char *)dst;
  psrc = (char *)src;
  dstlen = ft_strlen(dst);
  while ((dstlen + x) < dstsize)
  {
    pdst[x + dstlen] = psrc[x];
    x++;
  }
  pdst[x + dstlen] = '\0';
  return (dstlen + x);
}
