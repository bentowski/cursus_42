#include "parse.h"

int res(char *line, int i, t_res **res)
{
  t_res *new;

  new = *res;
  i++;
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG win_width, &win_heightOLUTION", i);
    return (-1);
  }
  while (line[i] >= '0' && line[i] <= '9')
    new->win_width = new->win_width * 10 + (line[i++] - 48);
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG win_width, &win_heightOLUTION", i);
    return (-1);
  }
  while (line[i] >= '0' && line[i] <= '9')
    new->win_height = (new->win_height * 10) + (line[i++] - 48);
  if (new->win_width > new->width_max)
    new->win_width = new->width_max;
  if (new->win_height > new->height_max)
    new->win_height = new->height_max;
  *res = new;
  return (i);
}

int ambiance(char *line, int i, t_ambiant **ambiant)
{
  t_ambiant *new;

  new = *ambiant;
  if (!(new->color = ft_calloc(1, sizeof(t_triade))))
    return (-1);
  if ((i = ft_space(line, i)) != -1)
    if (ft_routine(&new->lumens, line, &i, 1) != -1)
      if (new->lumens >= 0 && new->lumens <= 1)
        if ((i = ft_color(new->color, line, i)) != -1)
          if (ft_check_color_vdir(new->color, 2) != -1)
          {
            *ambiant = new;
            return (i);
          }
  return (-1);
}

int camera(char *line, int i, t_cams **cams)
{
  t_cams *new;
  t_cams *ptr;

  ptr = *cams;
  if ((new = ft_calloc(1, sizeof(t_cams))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
            if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
              if (ft_check_color_vdir(new->base->vdir, 1) != -1)
                if ((i = ft_space(line, i)) != -1)
                  if (ft_routine(&new->fov, line, &i, 2) != -1)
                    if (new->fov >= 0 && new->fov <= 180)
                    {
                      new->next = *cams;
                      ptr->previous = new;
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
      if (ft_routine(&new->lumens, line, &i, 2) != -1)
        if (new->lumens >= 0 && new->lumens <= 1)
          if ((i = ft_color(new->base->color, line, i)) != -1)
            if (ft_check_color_vdir(new->base->color, 2) != -1)
            {
              new->next = *lights;
              *lights = new;
              return (i);
            }
  ft_clear_lights(new);
  return (-1);
}
