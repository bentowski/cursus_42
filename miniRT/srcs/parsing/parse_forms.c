#include "../../minirt.h"

int init_sphere(char *line, int i, t_objs **objs)
{
  t_objs *new;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
          if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
            if ((i = ft_space(line, i)) != -1)
              if (ft_routine(&new->diam, line, &i, 2) != -1)
                if ((i = ft_color(new->base->color, line, i)) != -1)
                  if (ft_check_color_vdir(new->base->color, 2) != -1)
                      {
                        new->type = 1;
                        new->next = *objs;
                        *objs = new;
                        return (i);
                      }
	ft_clear_objs(new);
  return (-1);
}

int init_square(char *line, int i, t_objs **objs)
{
  t_objs *new;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
            if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
              if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
                if (ft_check_color_vdir(new->base->vdir, 1) != -1)
                  if ((i = ft_space(line, i)) != -1)
                    if (ft_routine(&new->height, line, &i, 2) != -1)
                      if ((i = ft_color(new->base->color, line, i)) != -1)
                        if (ft_check_color_vdir(new->base->color, 2) != -1)
                        {
                          new->type = 2;
                          new->next = *objs;
                          *objs = new;
                          return (i);
                        }
  ft_clear_objs(new);
  return (-1);
}

int init_plane(char *line, int i, t_objs **objs)
{
  t_objs *new;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
            if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
              if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
                if (ft_check_color_vdir(new->base->vdir, 1) != -1)
                  if ((i = ft_color(new->base->color, line, i)) != -1)
                    if (ft_check_color_vdir(new->base->color, 2) != -1)
                    {
                      new->type = 3;
                      new->next = *objs;
                      *objs = new;
                      return (i);
                    }
  ft_clear_objs(new);
  return (-1);
}

int init_cylinder(char *line, int i, t_objs **objs)
{
  t_objs *new;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
            if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
              if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
                if (ft_check_color_vdir(new->base->vdir, 1) != -1)
                  if ((i = ft_space(line, i)) != -1)
                    if (ft_routine(&new->diam, line, &i, 2) != -1)
                      if ((i = ft_space(line, i)) != -1)
                        if (ft_routine(&new->height, line, &i, 2) != -1)
                          if ((i = ft_color(new->base->color, line, i)) != -1)
                            if (ft_check_color_vdir(new->base->color, 2) != -1)
                            {
                              new->type = 4;
                              new->next = *objs;
                              *objs = new;
                              return (i);
                            }
  ft_clear_objs(new);
  return (-1);
}

int init_triangle(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_triade *test1;
  t_triade *test2;
  t_triade test3;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((new->p2 = ft_calloc(1, sizeof(t_triade))))
            if ((new->p3 = ft_calloc(1, sizeof(t_triade))))
              if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
                if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
                  if ((i = ft_coordonnees(new->p2, line, i)) != -1)
                    if ((i = ft_coordonnees(new->p3, line, i)) != -1)
                      if ((ft_vdir_tr(new->base, new->p2, new->p3)))
                        if ((i = ft_color(new->base->color, line, i)) != -1)
                          if (ft_check_color_vdir(new->base->color, 2) != -1)
                          {
                            new->type = 5;
                            new->next = *objs;
                            *objs = new;
                            return (i);
                          }
  ft_clear_objs(new);
  return (-1);
}
