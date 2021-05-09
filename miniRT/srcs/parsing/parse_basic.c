/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:41 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 21:56:30 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	res(char *line, int i, t_res **res)
{
	t_res	*new;

	new = *res;
	i++;
	if ((i = ft_space(line, i, 1)) == -1)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		new->width = new->width * 10 + (line[i++] - 48);
	if ((i = ft_space(line, i, 1)) == -1)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		new->height = (new->height * 10) + (line[i++] - 48);
	if (new->width > new->w_max)
		new->width = new->w_max;
	if (new->height > new->h_max)
		new->height = new->h_max;
	if ((i = ft_space(line, i, 2)) == -1)
		return (-1);
	*res = new;
	return (i);
}

int	ambiance(char *line, int i, t_ambiant **ambiant)
{
	t_ambiant	*new;

	new = *ambiant;
	if (!(new->color = ft_calloc(1, sizeof(t_triade))))
		return (-1);
	if ((i = ft_space(line, i, 1)) != -1)
		if (routine(&new->lumens, line, &i, 2) != -1)
			if (new->lumens >= 0 && new->lumens <= 1)
				if ((i = ft_color(new->color, line, i)) != -1)
					if (ft_check_color_vdir(new->color, 2) != -1)
						if ((i = ft_space(line, i, 2)) != -1)
						{
							*ambiant = new;
							return (i);
						}
	return (-1);
}

int	camera(char *line, int i, t_cams **cams)
{
	t_cams	*new;
	t_cams	*ptr;

	ptr = *cams;
	if ((new = ft_calloc(1, sizeof(t_cams))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
						if ((i = ft_structuration(new->base->vdir,
										line, i)) != -1)
							if (ft_check_color_vdir(new->base->vdir, 1) != -1)
								if ((i = ft_space(line, i, 1)) != -1)
									if (routine(&new->fov, line, &i, 2) != -1)
										if ((i = ft_space(line, i, 2)) != -1)
											if (new->fov >= 0
													&& new->fov <= 180)
											{
												new->next = *cams;
												ptr->previous = new;
												*cams = new;
												return (i);
											}
	ft_clear_cams(new);
	return (-1);
}

int	light(char *line, int i, t_lights **lights)
{
	t_lights	*new;

	if (!(new = ft_calloc(1, sizeof(t_lights))))
		return (-1);
	if (!(new->base = ft_calloc(1, sizeof(t_base))))
		return (-1);
	if (!(new->base->origins = ft_calloc(1, sizeof(t_triade))))
		return (-1);
	if (!(new->base->color = ft_calloc(1, sizeof(t_triade))))
		return (-1);
	if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
		if ((i = ft_space(line, i, 1)) != -1)
			if (routine(&new->lumens, line, &i, 2) != -1)
				if (new->lumens >= 0 && new->lumens <= 1)
					if ((i = ft_color(new->base->color, line, i)) != -1)
						if (ft_check_color_vdir(new->base->color, 2) != -1)
							if ((i = ft_space(line, i, 2)) != -1)
							{
								new->next = *lights;
								*lights = new;
								return (i);
							}
	ft_clear_lights(new);
	return (-1);
}
