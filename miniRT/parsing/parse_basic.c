#include "../minirt.h"

int resolution(t_map ****map, char *line, int i)
{
  t_map *new;

  new = ***map;
  i++;
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG win_width, &win_heightOLUTION", i);
    return (-1);
  }

  while (line[i] >= '0' && line[i] <= '9')
    new->resolution->win_width = new->resolution->win_width * 10 + (line[i++] - 48);
  printf("%s\n", "BOOM");
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG win_width, &win_heightOLUTION", i);
    return (-1);
  }

  while (line[i] >= '0' && line[i] <= '9')
    new->resolution->win_height = (new->resolution->win_height * 10) + (line[i++] - 48);
  ***map = new;
  return (i);
}

int ambiance(char *line, int i, t_ambiant **ambiant)
{
  t_ambiant *new;

  new = *ambiant;
  if (!(new->color = ft_calloc(1, sizeof(t_triade))))
    return (-1);
  if ((i = ft_space(line, i)) != -1)
    if ((new->lumens = ft_routine(new->lumens, line, &i, 1)) != -1)
      if (new->lumens >= 0 && new->lumens <= 1)
        if ((i = ft_color(new->color, line, i)) != -1)
          if (new->color->x >= 0 && new->color->x <= 255)
            if (new->color->y >= 0 && new->color->y <= 255)
              if (new->color->z >= 0 && new->color->z <= 255)
              {
                *ambiant = new;
                return (i);
              }
  return (-1);
}

int camera(char *line, int i, t_cams **cams)
{
  t_cams *new;

  if (!(new = ft_calloc(1, sizeof(t_cams))))
    return (-1);
  if (!(new->base = ft_calloc(1, sizeof(t_base))))
    return (-1);
  if (!(new->base->origins = ft_calloc(1, sizeof(t_triade))))
    return (-1);
  if (!(new->base->vdir = ft_calloc(1, sizeof(t_triade))))
    return (-1);
  if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
    if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
      if (new->base->vdir->x >= 0 && new->base->vdir->x <= 1)
        if (new->base->vdir->y >= 0 && new->base->vdir->y <= 1)
          if (new->base->vdir->z >= 0 && new->base->vdir->z <=1)
            if ((i = ft_space(line, i)) != -1)
              if ((new->fov = ft_routine(new->fov, line, &i, 2)) != -1)
                if (new->fov >= 0 && new->fov <= 180)
                {
                  new->next = *cams;
                  *cams = new;
                  return (i);
                }
  ft_clear_cams(new);
  return (-1);
}

int light(char *line, int i, t_lights **lights)
{
  t_lights *new;

  if (!(new = ft_calloc(1, sizeof(t_lights))))
    return (-1);
  if (!(new->base = ft_calloc(1, sizeof(t_base))))
    return (-1);
  if (!(new->base->origins = ft_calloc(1, sizeof(t_triade))))
    return (-1);
  if (!(new->base->color = ft_calloc(1, sizeof(t_triade))))
    return (-1);
  if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
    if ((i = ft_space(line, i)) != -1)
      if ((new->lumens = ft_routine(new->lumens, line, &i, 2)) != -1)
        if (new->lumens >= 0 && new->lumens <= 1)
          if ((i = ft_color(new->base->color, line, i)) != -1)
            if (new->base->color->x >= 0 && new->base->color->x <= 255)
              if (new->base->color->y >= 0 && new->base->color->y <= 255)
                if (new->base->color->z >= 0 && new->base->color->z <=255)
                {
                  new->next = *lights;
                  *lights = new;
                  return (i);
                }
  ft_clear_lights(new);
  return (-1);
}
