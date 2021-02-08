int ft_shadow_intersect(t_map *map, t_triade *p, t_triade ray)
{
  t_objs *ptr;
  t_objs *target;
  double test;

  ptr = map->objs;
  while (ptr->next)
  {
    if (ptr->type == 3)
      if ((test = intersect_plan(ray, ptr, p)) >= 0)
        return (1);
    if (ptr->type == 1)
      if ((test = intersect_sphere(ray, ptr, p)) >= 0)
        return (1);
    ptr = ptr->next;
  }
  return (0);
}

unsigned long int interlsphere(double t, t_triade ray, t_objs *ptr, t_map *map)
{
  double intens;
  double test;
  t_triade n;
  t_triade ldir;
  t_triade p;
  t_triade reflexion;
  unsigned long int ret;
  int shadow;

  if (!ptr)
    return (0);
  p.x = map->cams->base->origins->x + (t * ray.x);
  p.y = map->cams->base->origins->y + (t * ray.y);
  p.z = map->cams->base->origins->z + (t * ray.z);
  if (ptr->type == 1)
    n = get_norme(vector(&p, ptr->base->origins));
  else if (ptr->type == 3)
    n = get_norme(vector(ptr->base->vdir, map->vnull));
  ldir = get_norme(vector(map->lights->base->origins, &p));
  intens = 0;
  test = 0;
  p.x += n.x * 0.0001;
  p.y += n.y * 0.0001;
  p.z += n.z * 0.0001;
  if (!(shadow = ft_shadow_intersect(map, &p, ldir)))
  {
    intens = (map->lights->lumens);
    intens = intens / (ldir.x * ldir.x + ldir.y * ldir.y + ldir.z * ldir.z);
    if ((intens = intens * ldir.x * n.x + ldir.y * n.y + ldir.z * n.z) < 0)
      intens = 0;
    if ((ldir.x * n.x + ldir.y * n.y + ldir.z + n.z) < 0)
      intens = 0;
    // reflexion.x = ldir.x - (2 * (ldir.x * n.x) * n.x);
    // reflexion.y = ldir.y - (2 * (ldir.y * n.y) * n.y);
    // reflexion.z = ldir.z - (2 * (ldir.z * n.z) * n.z);
    // test = reflexion.x * ray.x;
    // test += reflexion.y * ray.y;
    // test += reflexion.z * ray.z;
    // if (test < 0)
    //   test = 0;
    // test = pow(test, 4);
  }
  return (ft_coloring(map->ambiant, ptr, intens));
}
