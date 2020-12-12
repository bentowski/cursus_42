#include "../minirt.h"

int init_sphere(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_base *ptr;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
    {
      ptr = new->base;
      if ((ptr->origins = ft_calloc(1, sizeof(t_triade))))
        if ((ptr->color = ft_calloc(1, sizeof(t_triade))))
          if ((i = ft_coordonnees(ptr->origins, line, i)) != -1)
            if ((i = ft_space(line, i)) != -1)
              if ((new->diam = ft_routine(new->diam, line, &i, 2)) != -1)
                if ((i = ft_color(ptr->color, line, i)) != -1)
                  if (ptr->color->x >= 0 && ptr->color->x <= 255)
                    if (ptr->color->y >= 0 && ptr->color->y <= 255)
                      if (ptr->color->z >= 0 && ptr->color->z <= 255)
                      {
                        new->type = 1;
                        new->next = *objs;
                        *objs = new;
                        return (i);
                      }
    }
	ft_clear_objs(new);
  return (-1);
}

int init_square(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_base *ptr;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
    {
      ptr = new->base;
      if ((ptr->origins = ft_calloc(1, sizeof(t_triade))))
        if ((ptr->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((ptr->color = ft_calloc(1, sizeof(t_triade))))
            if ((i = ft_coordonnees(ptr->origins, line, i)) != -1)
              if ((i = ft_structuration(ptr->vdir, line, i)) != -1)
                if (ptr->vdir->x >= 0 && ptr->vdir->x <= 1)
                  if (ptr->vdir->y >= 0 && ptr->vdir->y <= 1)
                    if (ptr->vdir->z >= 0 && ptr->vdir->z <=1)
                      if ((i = ft_space(line, i)) != -1)
                        if ((new->height = ft_routine(new->height, line, &i, 2)) != -1)
                          if ((i = ft_color(ptr->color, line, i)) != -1)
                            if (ptr->color->x >= 0 && ptr->color->x <= 255)
                              if (ptr->color->y >= 0 && ptr->color->y <= 255)
                                if (ptr->color->z >= 0 && ptr->color->z <= 255)
                                {
                                  new->type = 1;
                                  new->next = *objs;
                                  *objs = new;
                                  return (i);
                                }
    }
  ft_clear_objs(new);
  return (-1);
}

int init_plane(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_base *ptr;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
    {
      ptr = new->base;
      if ((ptr->origins = ft_calloc(1, sizeof(t_triade))))
        if ((ptr->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((ptr->color = ft_calloc(1, sizeof(t_triade))))
            if ((i = ft_coordonnees(ptr->origins, line, i)) != -1)
              if ((i = ft_structuration(ptr->vdir, line, i)) != -1)
                if (ptr->vdir->x >= 0 && ptr->vdir->x <= 1)
                  if (ptr->vdir->y >= 0 && ptr->vdir->y <= 1)
                    if (ptr->vdir->z >= 0 && ptr->vdir->z <=1)
                      if ((i = ft_color(ptr->color, line, i)) != -1)
                        if (ptr->color->x >= 0 && ptr->color->x <= 255)
                          if (ptr->color->y >= 0 && ptr->color->y <= 255)
                            if (ptr->color->z >= 0 && ptr->color->z <= 255)
                            {
                              new->type = 1;
                              new->next = *objs;
                              *objs = new;
                              return (i);
                            }
    }
  ft_clear_objs(new);
  return (-1);
}

int init_cylinder(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_base *ptr;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
    {
      ptr = new->base;
      if ((ptr->origins = ft_calloc(1, sizeof(t_triade))))
        if ((ptr->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((ptr->color = ft_calloc(1, sizeof(t_triade))))
            if ((i = ft_coordonnees(ptr->origins, line, i)) != -1)
              if ((i = ft_structuration(ptr->vdir, line, i)) != -1)
                if (ptr->vdir->x >= 0 && ptr->vdir->x <= 1)
                  if (ptr->vdir->y >= 0 && ptr->vdir->y <= 1)
                    if (ptr->vdir->z >= 0 && ptr->vdir->z <=1)
                      if ((i = ft_space(line, i)) != -1)
                        if ((new->diam = ft_routine(new->diam, line, &i, 2)) != -1)
                          if ((i = ft_space(line, i)) != -1)
                            if ((new->height = ft_routine(new->height, line, &i, 2)) != -1)
                              if ((i = ft_color(ptr->color, line, i)) != -1)
                                if (ptr->color->x >= 0 && ptr->color->x <= 255)
                                  if (ptr->color->y >= 0 && ptr->color->y <= 255)
                                    if (ptr->color->z >= 0 && ptr->color->z <= 255)
                                    {
                                      new->type = 1;
                                      new->next = *objs;
                                      *objs = new;
                                      return (i);
                                    }
    }
  ft_clear_objs(new);
  return (-1);
}

int init_triangle(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_base *ptr;

  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
    {
      ptr = new->base;
      if ((ptr->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->p2 = ft_calloc(1, sizeof(t_triade))))
          if ((new->p3 = ft_calloc(1, sizeof(t_triade))))
            if ((ptr->color = ft_calloc(1, sizeof(t_triade))))
              if ((i = ft_coordonnees(ptr->origins, line, i)) != -1)
                if ((i = ft_coordonnees(new->p2, line, i)) != -1)
                  if ((i = ft_coordonnees(new->p3, line, i)) != -1)
                    if ((i = ft_color(ptr->color, line, i)) != -1)
                      if (ptr->color->x >= 0 && ptr->color->x <= 255)
                        if (ptr->color->y >= 0 && ptr->color->y <= 255)
                          if (ptr->color->z >= 0 && ptr->color->z <= 255)
                          {
                            new->type = 1;
                            new->next = *objs;
                            *objs = new;
                            return (i);
                          }
    }
  ft_clear_objs(new);
  return (-1);
}
