/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:41 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/05 14:26:11 by bentowski        ###   ########.fr       */
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
