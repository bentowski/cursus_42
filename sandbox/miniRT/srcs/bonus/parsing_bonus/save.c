/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:29:45 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/09 02:43:17 by bentowski        ###   ########.fr       */
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

int construct_tr(t_objs *new, t_triade p1, t_triade p2, t_triade p3, t_objs *py)
{
	new->type = 5;
	new->base->origins->x = p1.x;
	new->base->origins->y = p1.y;
	new->base->origins->z = p1.z;
	new->p2->x = p2.x;
	new->p2->y = p2.y;
	new->p2->z = p2.z;
	new->p3->x = p3.x;
	new->p3->y = p3.y;
	new->p3->z = p3.z;
	if (!(ft_vdir_tr(new->base, new->p2, new->p3)))
		return (-1);
	new->base->color->x = py->base->color->x;
	new->base->color->y = py->base->color->y;
	new->base->color->z = py->base->color->z;
	return (1);
}

int new_tr(t_objs **ret, t_triade p1, t_triade p2, t_triade p3, t_objs *py)
{
	t_objs *new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->p2 = ft_calloc(1, sizeof(t_triade))))
					if ((new->p3 = ft_calloc(1, sizeof(t_triade))))
						if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
							if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
								if (construct_tr(new, p1, p2, p3, py))
								{
									*ret = new;
									return (1);
								}
	ft_clear_objs(new);
	return (-1);
}

void points_calcul(t_objs *py, t_triade p[5], t_triade vdir[3], t_base *base)
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

int	news_objs(t_objs *py, t_objs ***objs)
{
	t_objs	*tr[6];
	t_base *base;
	t_triade	p[6];
	t_triade	vdir[3];

	base = py->base;
	points_calcul(py, p, vdir, base);
	if (new_tr(&tr[0], p[0], p[1], p[3], py))
		if (new_tr(&tr[1], p[0], p[2], p[1], py))
			if (new_tr(&tr[2], p[0], p[2], p[4], py))
				if (new_tr(&tr[3], p[0], p[4], p[3], py))
					if (new_tr(&tr[4], p[4], p[2], p[1], py))
						if (new_tr(&tr[5], p[4], p[3], p[1], py))
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

int	init_py(char *line, int i, t_objs **objs)
{
	t_objs	*py;

	if ((py = ft_calloc(1, sizeof(t_objs))))
		if ((py->base = ft_calloc(1, sizeof(t_base))))
			if ((py->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((py->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((py->vdir2 = ft_calloc(1, sizeof(t_triade))))
						if ((py->base->color = ft_calloc(1, sizeof(t_triade))))
							if ((i = base_parse(line, py, i, 1)) != -1)
								if ((i = ft_structuration(py->vdir2, line, i)) != -1)
									if (ft_check_color_vdir(py->vdir2, 1) != -1)
										if ((i = ft_space(line, i, 1)) != -1)
											if (routine(&py->height, line, &i, 2) != -1)
												if ((i = ft_space(line, i, 1)) != -1)
													if (routine(&py->diam, line, &i, 2) != -1)
														if ((i = ft_color(py->base->color, line, i)) != -1)
															if (ft_check_color_vdir(py->base->color, 2) != -1)
																if ((i = ft_space(line, i, 2)) != -1)
																{
																	news_objs(py, &objs);
																	ft_clear_objs(py);
																	return (i);
																}
	ft_clear_objs(py);
	return (-1);
}
