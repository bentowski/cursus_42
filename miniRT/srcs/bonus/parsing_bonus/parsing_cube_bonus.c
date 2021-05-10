/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cube_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:04:40 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/08 21:05:04 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int new_sq(t_objs **ret, t_objs *py, double height, double size)
{
	t_objs *new;
	t_triade vdir;

	vdir = *py->base->vdir;
	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
					{
						new->type = 2;
						new->base->vdir->x = py->base->vdir->x;
						new->base->vdir->y = py->base->vdir->y;
						new->base->vdir->z = py->base->vdir->z;
						vdir = get_norme(vdir);
						new->base->origins->x = py->base->origins->x - (vdir.x * (height / 2));
						new->base->origins->y = py->base->origins->y - (vdir.y * (height / 2));
						new->base->origins->z = py->base->origins->z - (vdir.z * (height / 2));
						new->base->color->x = py->base->color->x;
						new->base->color->y = py->base->color->y;
						new->base->color->z = py->base->color->z;
						new->height = size;
						*ret = new;
						return (1);
					}
	ft_clear_objs(new);
	return (-1);
}
