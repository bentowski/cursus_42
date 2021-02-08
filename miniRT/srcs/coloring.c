#include "../minirt.h"

int get_rgb(int color1, int color2, double intensity, double lightning)
{
  int ret;

  ret = (color1 - (255 - color2)) * lightning;
  ret += (color1 - (255 - color2)) * intensity;
  if (ret > 255)
    ret = 255;
  if (ret < 0)
    ret = 0;
  return (ret);
}

unsigned long int get_color(t_ambiant *ambiant, t_objs *ptr, double intensity)
{
  int color;
  unsigned long int ret;

  if (!ptr)
    return (0);
  color = get_rgb(ambiant->color->x, ptr->base->color->x, intensity, ambiant->lumens);
  ret = color * 256 * 256;
  color = get_rgb(ambiant->color->y, ptr->base->color->y, intensity, ambiant->lumens);
  ret += color * 256;
  color = get_rgb(ambiant->color->z, ptr->base->color->z, intensity, ambiant->lumens);
  return (ret + color);
}
