#include "../minirt.h"

int verif(char *line, int i, t_map *map)
{
  char c;
  char p;

  c = line[i];
  p = line[i + 1];
  if (c && c != '\n' && c != '\t' && c != '\r' && c != '\v' && c != '\f')
    if (c != 'R' && c != 'A' && c != 'l')
    {
      if (c != 's' && c != 'c' && c != 'p' && c != 't')
      {
        printf("%s\n%s", "Error", "Invalid character detected");
        return (-1);
      }
      else if ((c == 'c' && p != 'y' && p != ' ') ||
      (c == 's' && p != 'p' && p != 'q') || (c == 'p' && p != 'l') ||
      (c == 't' && p != 'r'))
      {
        printf("%s\n%s", "Error", "Invalid character detected");
        return (-1);
      }
    }
  if (line[i] == 'R')
    if ((i = resolution(map, line, i)) == -1)
      printf("%s\n%s\n", "Error", "Invalid win_width, &win_heightolution data");
  return (i);
}

// int init_map(char *line, int i, t_list ***obj)
// {
//   if (line[i] == 'A')
//     if ((i = ambiance(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid ambiant data");
//   if (line[i] == 'c' && line[i + 1] != 'y')
//     if ((i = camera(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid camera data");
//   if (line[i] == 'l')
//     if ((i = light(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid light data");
//   if (line[i] == 's' && line[i + 1] == 'p')
//     if ((i = init_sphere(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid object data");
//   if (line[i] == 'p' && line[i + 1] == 'l')
//     if ((i = init_plane(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid object data");
//   if (line[i] == 's' && line[i + 1] == 'q')
//     if ((i = init_square(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid object data");
//   if (line[i] == 'c' && line[i + 1] == 'y')
//     if ((i = init_cylinder(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid object data");
//   if (line[i] == 't' && line[i + 1] == 'r')
//     if ((i = init_triangle(line, i, &obj)) == -1)
//       printf("%s\n%s\n", "Error", "Invalid object data");
//   return (i);
// }

int ft_parse(t_map *map, char *givedmap)
{
  int i;
  int ayet;
  int ryet;
  char *line;
  int fd;

  ayet = 0;
  ryet = 0;
  fd = open(givedmap, O_RDONLY);
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    if (foisdeux(line, &ayet, &ryet) == -1)
    {
      free(line);
      return (-1);
    }

    if ((i = verif(line, i, map)) == -1)
    {
      free(line);
      return (-1);
    }
    // if ((i = init_map(line, i, &map)) == -1)
    // {
    //   free(line);
    //   return (-1);
    // }
    free(line);
  }
  free(line);
  return (1);
}
