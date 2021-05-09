/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:24 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 00:35:24 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	ft_clear_base(t_base *base)
{
	if (base->origins)
		free(base->origins);
	if (base->vdir)
		free(base->vdir);
	if (base->color)
		free(base->color);
	free(base);
}

void		ft_clear_objs(t_objs *objs)
{
	t_objs *ptr;
	t_objs *tmp;

	ptr = objs;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->p2)
			free(ptr->p2);
		if (ptr->p3)
			free(ptr->p3);
		if (ptr->base)
			ft_clear_base(ptr->base);
		free(ptr);
		ptr = tmp;
	}
}

void		ft_clear_cams(t_cams *cams)
{
	t_cams *ptr;
	t_cams *tmp;

	ptr = cams;
	while (ptr->previous)
		ptr = ptr->previous;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->base)
			ft_clear_base(ptr->base);
		free(ptr);
		ptr = tmp;
	}
}

void		ft_clear_lights(t_lights *lights)
{
	t_lights *ptr;
	t_lights *tmp;

	ptr = lights;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->base)
			ft_clear_base(ptr->base);
		free(ptr);
		ptr = tmp;
	}
}

void		ft_clear(t_map *map)
{
	if (map->ambiant)
	{
		if (map->ambiant->color)
			free(map->ambiant->color);
		free(map->ambiant);
	}
	free(map->res);
	ft_clear_objs(map->objs);
	ft_clear_cams(map->cams);
	ft_clear_lights(map->lights);
	free(map->vnull);
	free(map);
}
