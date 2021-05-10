/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cube_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:04:40 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/10 07:36:27 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static void new_sq2(t_objs *new, t_objs *cu, t_triade vdir, int opt)
{
	new->base->origins->x = cu->base->origins->x +
		(vdir.x * (cu->height / 2) * opt);
	new->base->origins->y = cu->base->origins->y +
		(vdir.y * (cu->height / 2) * opt);
	new->base->origins->z = cu->base->origins->z +
		(vdir.z * (cu->height / 2) * opt);
	new->base->color->x = cu->base->color->x;
	new->base->color->y = cu->base->color->y;
	new->base->color->z = cu->base->color->z;
}

static int new_sq(t_objs ****ret, t_objs *cu, t_triade vdir, int opt)
{
	t_objs *new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
					{
						new->type = 2;
						new->base->vdir->x = vdir.x;
						new->base->vdir->y = vdir.y;
						new->base->vdir->z = vdir.z;
						vdir = get_norme(vdir);
						new->height = cu->height;
						new_sq2(new, cu, vdir, opt);
						new->next = ***ret;
						***ret = new;
						return (1);
					}
	ft_clear_objs(new);
	return (-1);
}

static int new_objs(t_objs *cu, t_objs ***objs)
{
	t_triade vdir;

	vdir.x = cu->vdir2->y * cu->base->vdir->z - cu->vdir2->z * cu->base->vdir->y;
	vdir.y = cu->vdir2->z * cu->base->vdir->x - cu->vdir2->x * cu->base->vdir->z;
	vdir.z = cu->vdir2->x * cu->base->vdir->y - cu->vdir2->y * cu->base->vdir->x;
	new_sq(&objs, cu, *cu->base->vdir, -1);
	new_sq(&objs, cu, *cu->vdir2, -1);
	new_sq(&objs, cu, *cu->base->vdir, 1);
	new_sq(&objs, cu, *cu->vdir2, 1);
	new_sq(&objs, cu, vdir, 1);
	new_sq(&objs, cu, vdir, -1);
	return (1);
}

int			init_cu(char *line, int i, t_objs **objs)
{
	t_objs	*cu;

	if ((cu = ft_calloc(1, sizeof(t_objs))))
		if ((cu->base = ft_calloc(1, sizeof(t_base))))
			if ((cu->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((cu->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((cu->vdir2 = ft_calloc(1, sizeof(t_triade))))
						if ((cu->base->color = ft_calloc(1, sizeof(t_triade))))
							if ((i = base_parse(line, cu, i, 1)) != -1)
								if ((i = ft_structuration(cu->vdir2, line, i)) != -1)
									if (ft_check_color_vdir(cu->vdir2, 1) != -1)
										if ((i = ft_space(line, i, 1)) != -1)
											if (routine(&cu->height, line, &i, 2) != -1)
												if ((i = ft_color(cu->base->color, line, i)) != -1)
													if (ft_check_color_vdir(cu->base->color, 2) != -1)
														if ((i = ft_space(line, i, 2)) != -1)
														{
															new_objs(cu, &objs);
															ft_clear_objs(cu);
															return (i);
														}
	ft_clear_objs(cu);
	return (-1);
}
