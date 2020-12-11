#include "minirt.h"

void ft_clear_base(t_base *base)
{
  if (base->origins)
    free(base->origins);
  if (base->vdir)
    free(base->vdir);
  if (base->color)
    free(base->color);
  free(base);
}

void ft_clear_objs(t_objs *objs)
{
  t_objs *ptr;
  t_objs *tmp;

  ptr = objs;
  while (ptr)
  {
    tmp = ptr->next;
    if (ptr->p2)
      free(ptr->p2);
    if (ptr->p3)
      free(ptr->p3);
    if (ptr->base)
      ft_clear_base(ptr->base);
    free(ptr);
    ptr = tmp;
  }
}

void ft_clear_cams(t_cams *cams)
{
  t_cams *ptr;
  t_cams *tmp;

  ptr = cams;
  while (ptr)
  {
    tmp = ptr->next;
    if (ptr->base)
      ft_clear_base(ptr->base);
    free(ptr);
    ptr = tmp;
  }
}

void ft_clear_lights(t_lights *lights)
{
  t_lights *ptr;
  t_lights *tmp;

  ptr = lights;
  while (ptr)
  {
    tmp = ptr->next;
    if (ptr->base)
      ft_clear_base(ptr->base);
    free(ptr);
    ptr = tmp;
  }
}

void ft_clear(t_map *map)
{
  if (map->ambiant)
  {
    if (map->ambiant->color)
      free(map->ambiant->color);
    free(map->ambiant);
  }
  free(map->resolution);
  ft_clear_objs(map->objs);
  ft_clear_cams(map->cams);
  ft_clear_lights(map->lights);
  free(map);
}
