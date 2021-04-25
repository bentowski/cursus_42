/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_forms_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:46 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 21:56:28 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_vecteur(t_triade *new, char *line, int i)
{
	if (routine(&new->x, line, &i, 1) == -1)
		return (-1);
	if (line[i++] != ',')
		return (-1);
	if (routine(&new->y, line, &i, 1) == -1)
		return (-1);
	if (line[i++] != ',')
		return (-1);
	if (routine(&new->z, line, &i, 2) == -1)
		return (-1);
	return (i);
}

int	ft_structuration(t_triade *new, char *line, int i)
{
	if ((i = ft_space(line, i, 1)) == -1)
		return (-1);
	if ((i = ft_vecteur(new, line, i)) == -1)
		return (-1);
	return (i);
}

int	ft_color(t_triade *color, char *line, int i)
{
	if ((i = ft_space(line, i, 1)) == -1)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		color->x = color->x * 10 + line[i++] - 48;
	if (line[i++] != ',')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		color->y = color->y * 10 + line[i++] - 48;
	if (line[i++] != ',')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		color->z = color->z * 10 + line[i++] - 48;
	return (i);
}

int	ft_coordonnees(t_triade *new, char *line, int i)
{
	if ((i = ft_space(line, i, 1)) != -1)
		if (routine(&new->x, line, &i, 1) != -1)
			if (line[i++] == ',')
				if (routine(&new->y, line, &i, 1) != -1)
					if (line[i++] == ',')
						if (routine(&new->z, line, &i, 2) != -1)
							return (i);
	return (-1);
}

int	ft_check_color_vdir(t_triade *check, int opt)
{
	int	min;
	int	max;

	if (opt == 1)
	{
		min = -1;
		max = 1;
	}
	if (opt == 2)
	{
		min = 0;
		max = 255;
	}
	if (check->x >= min && check->x <= max)
		if (check->y >= min && check->y <= max)
			if (check->z >= min && check->z <= max)
				return (1);
	return (-1);
}
