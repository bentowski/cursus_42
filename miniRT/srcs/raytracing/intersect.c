/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:09 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 00:35:10 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static int		square(double test, t_objs *ptr, t_triade ray, t_triade *origin)
{
	t_triade	p;
	t_triade	dist;
	double		inside;

	inside = ptr->height / 2;
	p.x = origin->x + test * ray.x;
	p.y = origin->y + test * ray.y;
	p.z = origin->z + test * ray.z;
	dist.x = fabs(p.x - ptr->base->origins->x);
	dist.y = fabs(p.y - ptr->base->origins->y);
	dist.z = fabs(p.z - ptr->base->origins->z);
	if (dist.x <= inside && dist.y <= inside && dist.z <= inside)
		return (1);
	return (-1);
}

static double	triangle(double test,
		t_objs *ptr, t_triade ray, t_triade *origin)
{
	t_triade p;
	t_triade side[3];
	t_triade i[3];
	t_triade j[3];

	p.x = origin->x + test * ray.x;
	p.y = origin->y + test * ray.y;
	p.z = origin->z + test * ray.z;
	side[0] = subs(*ptr->p2, *ptr->base->origins);
	side[1] = subs(*ptr->p3, *ptr->p2);
	side[2] = subs(*ptr->base->origins, *ptr->p3);
	i[0] = subs(p, *ptr->base->origins);
	i[1] = subs(p, *ptr->p2);
	i[2] = subs(p, *ptr->p3);
	j[0] = crossprod(side[0], i[0]);
	j[1] = crossprod(side[1], i[1]);
	j[2] = crossprod(side[2], i[2]);
	if ((scale(ptr->base->vdir, &j[0]) > 0)
			&& (scale(ptr->base->vdir, &j[1]) > 0)
			&& (scale(ptr->base->vdir, &j[2]) > 0))
		return (1);
	return (-1);
}

double			intersect_plan(t_triade ray, t_objs *ptr, t_triade *origins)
{
	t_triade alpha;
	t_triade vdir;

	vdir = get_norme(*ptr->base->vdir);
	alpha = subs(*ptr->base->origins, *origins);
	if (ft_angle(&alpha, &vdir) >= 0)
	{
		vdir.x = -vdir.x;
		vdir.y = -vdir.y;
		vdir.z = -vdir.z;
		*ptr->base->vdir = vdir;
	}
	alpha.x = scale(&alpha, &vdir) / scale(&ray, &vdir);
	if (alpha.x <= 0)
		return (-1);
	if (ptr->type == 3)
		return (alpha.x);
	if (ptr->type == 2)
		if (square(alpha.x, ptr, ray, origins) == 1)
			return (alpha.x);
	if (ptr->type == 5)
		if (triangle(alpha.x, ptr, ray, origins) == 1)
			return (alpha.x);
	return (-1);
}

double			intersect_sphere(t_triade ray, t_objs *ptr, t_triade *origins)
{
	t_triade alpha;
	t_triade polynome;

	polynome.x = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
	polynome.y = ray.x * (origins->x - ptr->base->origins->x);
	polynome.y += ray.y * (origins->y - ptr->base->origins->y);
	polynome.y += ray.z * (origins->z - ptr->base->origins->z);
	polynome.y = polynome.y * 2;
	polynome.z = pow((origins->x - ptr->base->origins->x), 2);
	polynome.z += pow((origins->y - ptr->base->origins->y), 2);
	polynome.z += pow((origins->z - ptr->base->origins->z), 2);
	polynome.z -= (ptr->diam / 2) * (ptr->diam / 2);
	alpha.z = ((polynome.y) * (polynome.y)) - (4 * polynome.x * polynome.z);
	if (alpha.z >= 0)
	{
		alpha.x = (-polynome.y - sqrt(alpha.z)) / (2 * polynome.x);
		alpha.y = (-polynome.y + sqrt(alpha.z)) / (2 * polynome.x);
		if (alpha.y < 0)
			return (-1);
		if (alpha.x >= 0)
			return (alpha.x);
		return (alpha.y);
	}
	return (-1);
}

double			intersect_cy(t_triade ray, t_objs *ptr, t_triade *origins)
{
	t_triade	tmp[4];
	double		ret[4];

	tmp[0] = subs(*origins, *ptr->base->origins);
	tmp[1] = subs(ray, increase(*ptr->base->vdir,
			scale(&ray, ptr->base->vdir)));
	tmp[2] = subs(subs(*origins, *ptr->base->origins),
		increase(*ptr->base->vdir, scale(&tmp[0], ptr->base->vdir)));
	ret[0] = calcul_polynome(scale(&tmp[1], &tmp[1]), 2 * scale(&tmp[1],
		&tmp[2]), (scale(&tmp[2], &tmp[2]) - pow((ptr->diam / 2), 2)), 1);
	ret[1] = calcul_polynome(scale(&tmp[1], &tmp[1]), 2 * scale(&tmp[1],
		&tmp[2]), (scale(&tmp[2], &tmp[2]) - pow((ptr->diam / 2), 2)), 2);
	tmp[3] = subs(increase(ray, ret[0]), subs(*ptr->base->origins, *origins));
	ret[2] = scale(ptr->base->vdir, &tmp[3]);
	tmp[3] = subs(increase(ray, ret[1]), subs(*ptr->base->origins, *origins));
	ret[3] = scale(ptr->base->vdir, &tmp[3]);
	return (cylinder_return(ret, ptr));
}
