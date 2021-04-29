/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:54 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/28 14:51:34 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static double	routinedeux(double x, char *line, int **i)
{
	double	tmp;
	int		div;

	tmp = .0;
	div = 0;
	**i = **i + 1;
	while (line[**i] >= '0' && line[**i] <= '9')
	{
		tmp = tmp * 10 + line[**i] - 48;
		div++;
		**i = **i + 1;
	}
	while (div-- > 0)
		tmp = tmp / 10;
	x = x + tmp;
	return (x);
}

int				routine(double *x, char *line, int *i, int opt)
{
	int	neg;

	neg = 1;
	if ((line[*i] != '-') && (line[*i] < 48 || line[*i] > 57))
		return (-1);
	if (line[*i] == '-')
	{
		neg = -1;
		*i = *i + 1;
	}
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		*x = *x * 10 + line[*i] - 48;
		*i = *i + 1;
	}
	if (line[*i] == '.')
		*x = routinedeux(*x, line, &i);
	else if (line[*i] != ',' && opt == 1)
		return (-1);
	*x = *x * neg;
	return (1);
}

int				foisdeux(char *line, int *ayet, int *ryet)
{
	if (line[0] == 'R')
	{
		if (*ryet == 1)
		{
			printf("%s\n%s\n", "Error", "Resolution x2");
			return (-1);
		}
		else
			*ryet = *ryet + 1;
	}
	if (line[0] == 'A')
	{
		if (*ayet == 1)
		{
			printf("%s\n%s\n", "Error", "Ambiant x2");
			return (-1);
		}
		else
			*ayet = *ayet + 1;
	}
	return (0);
}

int				ft_space(char *line, int i, int opt)
{
	if (opt == 1)
	{
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			if (line[i++] != ' ')
				return (-1);
	}
	else if (opt == 2)
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '\0')
				return (-1);
			i++;
		}
	return (i);
}

int				ft_vdir_tr(t_base *ptr, t_triade *p2, t_triade *p3)
{
	t_triade	n;
	t_triade	n2;

	n.x = p2->x - ptr->origins->x;
	n.y = p2->y - ptr->origins->y;
	n.z = p2->z - ptr->origins->z;
	n2.x = p3->x - ptr->origins->x;
	n2.y = p3->y - ptr->origins->y;
	n2.z = p3->z - ptr->origins->z;
	ptr->vdir->x = n.y * n2.z - n.z * n2.y;
	ptr->vdir->y = n.z * n2.x - n.x * n2.z;
	ptr->vdir->z = n.x * n2.y - n.y * n2.x;
	return (1);
}
