/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:25:07 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/09 02:03:34 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static int	camera2(char *line, int i, t_cams **ret)
{
	t_cams *new;

	new = *ret;
	if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
		if (ft_check_color_vdir(new->base->vdir, 1) != -1)
			if ((i = ft_space(line, i, 1)) != -1)
				if (routine(&new->fov, line, &i, 2) != -1)
					if ((i = ft_space(line, i, 2)) != -1)
					{
						*ret = new;
						return (i);
					}
	return (-1);
}

int			camera(char *line, int i, t_cams **cams)
{
	t_cams	*new;
	t_cams	*ptr;

	ptr = *cams;
	if ((new = ft_calloc(1, sizeof(t_cams))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
						if ((i = camera2(line, i, &new)) != -1)
							if (new->fov >= 0 && new->fov <= 180)
							{
								if (new->fov == 180)
									new->fov = 179;
								new->next = *cams;
								ptr->previous = new;
								*cams = new;
								return (i);
							}
	ft_clear_cams(new);
	return (-1);
}

static int	light2(char *line, int i, t_lights **ret)
{
	t_lights *new;

	new = *ret;
	if ((i = ft_space(line, i, 1)) != -1)
		if (routine(&new->fov, line, &i, 2) != -1)
			if ((i = ft_space(line, i, 1)) != -1)
				if ((i = ft_color(new->base->color, line, i)) != -1)
					if (ft_check_color_vdir(new->base->color, 2) != -1)
						if ((i = ft_space(line, i, 2)) != -1)
						{
							*ret = new;
							return (i);
						}
	return (-1);
}

int			light(char *line, int i, t_lights **lights)
{
	t_lights	*new;

	if ((new = ft_calloc(1, sizeof(t_lights))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
						if ((i =
						ft_coordonnees(new->base->origins, line, i)) != -1)
							if ((i =
							ft_structuration(new->base->vdir, line, i)) != -1)
								if (ft_check_color_vdir(new->base->vdir, 1) != -1)
									if ((i =
									ft_space(line, i, 1)) != -1)
										if (routine(
										&new->lumens, line, &i, 2) != -1)
											if (new->lumens
											>= 0 && new->lumens <= 1)
												if ((i =
												light2(line, i, &new)) != -1)
												{
													new->next = *lights;
													*lights = new;
													return (i);
												}
	ft_clear_lights(new);
	return (-1);
}
