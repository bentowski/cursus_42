#include "../minirt.h"

int get_rgb(int color1, int color2, double intensity, double light)
{
  int ret;

  ret = (color1 - (255 - color2)) * light;
  ret += (color1 - (255 - color2)) * intensity;
  if (ret > 255)
    return (255);
  if (ret < 0)
    return (0);
  return (ret);
}

unsigned long int get_color(t_ambiant *ambiant, t_objs *ptr, double intensity)
{
  t_triade color1;
  t_triade color2;
  double light;
  unsigned long int ret;

  if (!ptr)
    return (0);
  color1 = *ambiant->color;
  color2 = *ptr->base->color;
  light = ambiant->lumens;
  ret = get_rgb(color1.x, color2.x, intensity, light) * 256 * 256;
  ret += get_rgb(color1.y, color2.y, intensity, light) * 256;
  ret += get_rgb(color1.z, color2.z, intensity, light);
  return (ret);
}
