/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:05 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 01:51:57 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static int	get_rgb(t_ambiant *amb, int *ctab, int c3, double intens)
{
	int			ret;

	ret = (ctab[0] - (255 - ctab[1])) * amb->lumens;
	ret += (c3 - (255 - ctab[1])) * intens;
	if (ret > 255)
		return (255);
	if (ret < 0)
		return (0);
	return (ret);
}

t_triade	get_color(t_ambiant *amb, t_lights *l, t_objs *ptr, double intens)
{
	int			x[2];
	int			y[2];
	int			z[2];
	t_triade	color2;
	t_triade	ret;

	if (!ptr)
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 0;
		return (ret);
	}
	color2 = *ptr->base->color;
	x[0] = amb->color->x;
	x[1] = color2.x;
	y[0] = amb->color->y;
	y[1] = color2.y;
	z[0] = amb->color->z;
	z[1] = color2.z;
	ret.x = get_rgb(amb, x, l->base->color->x, intens);
	ret.y = get_rgb(amb, y, l->base->color->y, intens);
	ret.z = get_rgb(amb, z, l->base->color->z, intens);
	return (ret);
}
