/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_py2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:08:14 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/10 06:50:34 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static int	construct_tr(t_objs *new, t_triade p[3], t_objs *py)
{
	new->type = 5;
	new->base->origins->x = p[0].x;
	new->base->origins->y = p[0].y;
	new->base->origins->z = p[0].z;
	new->p2->x = p[1].x;
	new->p2->y = p[1].y;
	new->p2->z = p[1].z;
	new->p3->x = p[2].x;
	new->p3->y = p[2].y;
	new->p3->z = p[2].z;
	if (!(ft_vdir_tr(new->base, new->p2, new->p3)))
		return (-1);
	new->base->color->x = py->base->color->x;
	new->base->color->y = py->base->color->y;
	new->base->color->z = py->base->color->z;
	return (1);
}

static int	new_tr(t_objs ***ret, t_triade p[3], t_objs *py)
{
	t_objs	*new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->p2 = ft_calloc(1, sizeof(t_triade))))
					if ((new->p3 = ft_calloc(1, sizeof(t_triade))))
						if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
							if ((new->base->color =
							ft_calloc(1, sizeof(t_triade))))
								if (construct_tr(new, p, py))
								{
									**ret = new;
									return (1);
								}
	ft_clear_objs(new);
	return (-1);
}

int			news_objs2(t_objs **tr, t_triade p[6], t_objs *py, int opt)
{
	t_triade	e[3];

	if (opt <= 4)
		e[0] = p[0];
	else if (opt >= 5)
		e[0] = p[1];
	if (opt == 1)
		e[1] = p[1];
	else if (opt == 2 || opt == 3 || opt == 5)
		e[1] = p[2];
	else if (opt == 6)
		e[1] = p[3];
	else if (opt == 4)
		e[1] = p[4];
	if (opt == 2 || opt >= 5)
		e[2] = p[4];
	else if (opt == 1 || opt == 4)
		e[2] = p[3];
	else if (opt == 3)
		e[2] = p[4];
	if ((new_tr(&tr, e, py)))
		return (1);
	return (-1);
}
