/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:33 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 00:35:34 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_triade	subs(t_triade t1, t_triade t2)
{
	t_triade	t3;

	t3.x = t1.x - t2.x;
	t3.y = t1.y - t2.y;
	t3.z = t1.z - t2.z;
	return (t3);
}

t_triade	increase(t_triade t1, double n)
{
	t_triade	ret;

	ret.x = t1.x * n;
	ret.y = t1.y * n;
	ret.z = t1.z * n;
	return (ret);
}

t_triade	add_vectors(t_triade u, t_triade v)
{
	t_triade	ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;
	ret.z = u.z + v.z;
	return (ret);
}

double		scale(t_triade *t1, t_triade *t2)
{
	double	ret;

	ret = t1->x * t2->x + t1->y * t2->y + t1->z * t2->z;
	return (ret);
}

t_triade	crossprod(t_triade u, t_triade v)
{
	t_triade	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
