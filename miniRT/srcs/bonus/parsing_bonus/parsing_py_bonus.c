/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_py_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:29:45 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/10 06:37:24 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static void	points_calcul(t_objs *py, t_triade p[6],
		t_triade vdir[3], t_base *base)
{
	vdir[0] = get_norme(*base->vdir);
	vdir[1] = get_norme(*py->vdir2);
	vdir[2].x = py->vdir2->y * base->vdir->z - py->vdir2->z * base->vdir->y;
	vdir[2].y = py->vdir2->z * base->vdir->x - py->vdir2->x * base->vdir->z;
	vdir[2].z = py->vdir2->x * base->vdir->y - py->vdir2->y * base->vdir->x;
	vdir[2] = get_norme(vdir[2]);
	p[0].x = py->base->origins->x + (vdir[0].x * (py->height / 2));
	p[0].y = py->base->origins->y + (vdir[0].y * (py->height / 2));
	p[0].z = py->base->origins->z + (vdir[0].z * (py->height / 2));
	p[6].x = py->base->origins->x - (vdir[0].x * (py->height / 2));
	p[6].y = py->base->origins->y - (vdir[0].y * (py->height / 2));
	p[6].z = py->base->origins->z - (vdir[0].z * (py->height / 2));
	p[1].x = p[6].x - vdir[1].x * (py->diam / 2) - vdir[2].x * (py->diam / 2);
	p[1].y = p[6].y - vdir[1].y * (py->diam / 2) - vdir[2].y * (py->diam / 2);
	p[1].z = p[6].z - vdir[1].z * (py->diam / 2) - vdir[2].z * (py->diam / 2);
	p[2].x = p[6].x - vdir[1].x * (py->diam / 2) + vdir[2].x * (py->diam / 2);
	p[2].y = p[6].y - vdir[1].y * (py->diam / 2) + vdir[2].y * (py->diam / 2);
	p[2].z = p[6].z - vdir[1].z * (py->diam / 2) + vdir[2].z * (py->diam / 2);
	p[3].x = p[6].x + vdir[1].x * (py->diam / 2) - vdir[2].x * (py->diam / 2);
	p[3].y = p[6].y + vdir[1].y * (py->diam / 2) - vdir[2].y * (py->diam / 2);
	p[3].z = p[6].z + vdir[1].z * (py->diam / 2) - vdir[2].z * (py->diam / 2);
	p[4].x = p[6].x + vdir[1].x * (py->diam / 2) + vdir[2].x * (py->diam / 2);
	p[4].y = p[6].y + vdir[1].y * (py->diam / 2) + vdir[2].y * (py->diam / 2);
	p[4].z = p[6].z + vdir[1].z * (py->diam / 2) + vdir[2].z * (py->diam / 2);
}

static int	news_objs(t_objs *py, t_objs ***objs)
{
	t_objs		*tr[6];
	t_base		*base;
	t_triade	p[6];
	t_triade	vdir[3];

	base = py->base;
	points_calcul(py, p, vdir, base);
	if (news_objs2(&tr[0], p, py, 1))
		if (news_objs2(&tr[1], p, py, 2))
			if (news_objs2(&tr[2], p, py, 3))
				if (news_objs2(&tr[3], p, py, 4))
					if (news_objs2(&tr[4], p, py, 5))
						if (news_objs2(&tr[5], p, py, 6))
						{
							tr[0]->next = tr[1];
							tr[1]->next = tr[2];
							tr[2]->next = tr[3];
							tr[3]->next = tr[4];
							tr[4]->next = tr[5];
							tr[5]->next = **objs;
							**objs = tr[0];
							return (1);
						}
	return (-1);
}

static int	init_py2(char *line, int i, t_objs *py)
{
	if (ft_check_color_vdir(py->vdir2, 1) != -1)
		if ((i = ft_space(line, i, 1)) != -1)
			if (routine(&py->height, line, &i, 2) != -1)
				if ((i = ft_space(line, i, 1)) != -1)
					if (routine(&py->diam, line, &i, 2) != -1)
						if ((i = ft_color(py->base->color, line, i)) != -1)
							if (ft_check_color_vdir(py->base->color, 2) != -1)
								if ((i = ft_space(line, i, 2)) != -1)
									return (i);
	return (-1);
}

int			init_py(char *line, int i, t_objs **objs)
{
	t_objs	*py;

	if ((py = ft_calloc(1, sizeof(t_objs))))
		if ((py->base = ft_calloc(1, sizeof(t_base))))
			if ((py->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((py->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((py->vdir2 = ft_calloc(1, sizeof(t_triade))))
						if ((py->base->color = ft_calloc(1, sizeof(t_triade))))
							if ((i =
							base_parse(line, py, i, 1)) != -1)
								if ((i =
								ft_structuration(py->vdir2, line, i)) != -1)
									if ((i =
									init_py2(line, i, py)) != -1)
									{
										news_objs(py, &objs);
										ft_clear_objs(py);
										return (i);
									}
	ft_clear_objs(py);
	return (-1);
}
