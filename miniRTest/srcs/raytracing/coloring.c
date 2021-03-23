#include "raytracing.h"

int get_rgb(int color1, int color2, int color3, double intensity, double light)
{
  int ret;

  ret = (color1 - (255 - color2)) * light;
  ret += (color3 - (255 - color2)) * intensity;
  if (ret > 255)
    return (255);
  if (ret < 0)
    return (0);
  return (ret);
}

t_triade get_color(t_ambiant *ambiant, t_lights *lights, t_objs *ptr, double intensity)
{
  t_triade color1;
  t_triade color2;
  double light;
  t_triade ret;

  if (!ptr)
  {
    ret.x = 0;
    ret.y = 0;
    ret.z = 0;
    return (ret);
  }
  color1 = *ambiant->color;
  color2 = *ptr->base->color;
  light = ambiant->lumens;
  ret.x = get_rgb(color1.x, color2.x, lights->base->color->x, intensity, light);
  ret.y = get_rgb(color1.y, color2.y, lights->base->color->y, intensity, light);
  ret.z = get_rgb(color1.z, color2.z, lights->base->color->z, intensity, light);
  return (ret);
}
