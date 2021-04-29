/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:58 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/28 16:50:07 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			base_parse(char *line, t_objs *new, int i, int opt)
{
	if (opt == 0)
	{
		if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
			if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
				if ((new->p2 = ft_calloc(1, sizeof(t_triade))))
					if ((new->p3 = ft_calloc(1, sizeof(t_triade))))
						if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
							return (i);
	}
	else if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
		if ((i = ft_structuration(new->base->vdir, line, i)) != -1)
			if (ft_check_color_vdir(new->base->vdir, 1) != -1)
			{
				if (opt == 2)
				{
					if ((i = ft_space(line, i, 1)) != -1)
						if (routine(&new->diam, line, &i, 2) != -1)
							return (i);
					return (-1);
				}
				else
					return (i);
			}
	return (-1);
}

static int	verif(char *line, int i)
{
	char	c;
	char	p;

	c = line[i];
	p = line[i + 1];
	if (c && c != '\n' && c != '\t' && c != '\r' && c != '\v' && c != '\f')
		if (c != 'R' && c != 'A' && c != 'l')
		{
			if (c != 's' && c != 'c' && c != 'p' && c != 't')
			{
				printf("%s\n%s", "Error", "Invalid character detected");
				return (-1);
			}
			else if ((c == 'c' && p != 'y' && p != ' ') ||
					(c == 's' && p != 'p' && p != 'q') ||
					(c == 'p' && p != 'l') || (c == 't' && p != 'r'))
			{
				printf("%s\n%s", "Error", "Invalid character detected");
				return (-1);
			}
		}
	return (i);
}

static int	other_maping(char *line, int i, t_map ***map)
{
	t_map	*new;

	new = **map;
	if (line[i] == 'R')
		if ((i = res(line, i, &new->res)) == -1)
			printf("%s\n%s\n", "Error", "Invalid resolution data");
	if (line[i] == 'A')
		if ((i = ambiance(line, i + 1, &new->ambiant)) == -1)
			printf("%s\n%s\n", "Error", "Invalid ambiant data");
	if (line[i] == 'c' && line[i + 1] != 'y')
		if ((i = camera(line, i + 1, &new->cams)) == -1)
			printf("%s\n%s\n", "Error", "Invalid camera data");
	if (line[i] == 'l')
		if ((i = light(line, i + 1, &new->lights)) == -1)
			printf("%s\n%s\n", "Error", "Invalid light data");
	return (i);
}

static int	objects_mapping(char *line, int i, t_map ***map)
{
	t_map	*new;

	new = **map;
	if (line[i] == 's' && line[i + 1] == 'p')
		if ((i = init_sphere(line, i + 2, &new->objs)) == -1)
			printf("%s\n%s\n", "Error", "Invalid object data");
	if (line[i] == 'p' && line[i + 1] == 'l')
		if ((i = init_plane(line, i + 2, &new->objs)) == -1)
			printf("%s\n%s\n", "Error", "Invalid object data");
	if (line[i] == 's' && line[i + 1] == 'q')
		if ((i = init_square(line, i + 2, &new->objs)) == -1)
			printf("%s\n%s\n", "Error", "Invalid object data");
	if (line[i] == 'c' && line[i + 1] == 'y')
		if ((i = init_cylinder(line, i + 2, &new->objs)) == -1)
			printf("%s\n%s\n", "Error", "Invalid object data");
	if (line[i] == 't' && line[i + 1] == 'r')
		if ((i = init_triangle(line, i + 2, &new->objs)) == -1)
			printf("%s\n%s\n", "Error", "Invalid object data");
	return (i);
}

int			ft_parse(t_map **map, char *givedmap)
{
	int		i;
	int		ayet;
	int		ryet;
	char	*line;
	int		fd;

	if ((fd = open(givedmap, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			i = 0;
			if ((i = foisdeux(line, &ayet, &ryet)) != -1)
				if ((i = verif(line, i)) != -1)
					if ((i = other_maping(line, i, &map)) != -1)
						i = objects_mapping(line, i, &map);
			free(line);
			if (i++ == -1)
				return (-1);
		}
		free(line);
		return (1);
	}
	printf("%s\n%s\n", "Error", "Invalid map file");
	close(fd);
	return (-1);
}
