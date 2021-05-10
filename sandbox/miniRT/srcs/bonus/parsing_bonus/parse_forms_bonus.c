/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_forms_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:50 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/07 15:55:28 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	init_sphere(char *line, int i, t_objs **objs)
{
	t_objs	*new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
					if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
						if ((i = ft_space(line, i, 1)) != -1)
							if (routine(&new->diam, line, &i, 2) != -1)
								if ((i = ft_color(
									new->base->color, line, i)) != -1)
									if (ft_check_color_vdir(
										new->base->color, 2) != -1)
										if ((i = ft_space(line, i, 2)) != -1)
										{
											new->type = 1;
											new->next = *objs;
											*objs = new;
											return (i);
										}
	ft_clear_objs(new);
	return (-1);
}

int	init_square(char *line, int i, t_objs **objs)
{
	t_objs	*new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
						if ((i = base_parse(line, new, i, 1)) != -1)
							if ((i = ft_space(line, i, 1)) != -1)
								if (routine(&new->height, line, &i, 2) != -1)
									if ((i = ft_color(new->base->color,
										line, i)) != -1)
										if (ft_check_color_vdir(
											new->base->color, 2) != -1)
											if ((i = ft_space(
												line, i, 2)) != -1)
											{
												new->type = 2;
												new->next = *objs;
												*objs = new;
												return (i);
											}
	ft_clear_objs(new);
	return (-1);
}

int	init_plane(char *line, int i, t_objs **objs)
{
	t_objs	*new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
						if ((i = base_parse(line, new, i, 1)) != -1)
							if ((i = ft_color(new->base->color, line, i)) != -1)
								if (ft_check_color_vdir(
									new->base->color, 2) != -1)
									if ((i = ft_space(line, i, 2)) != -1)
									{
										new->type = 3;
										new->next = *objs;
										*objs = new;
										return (i);
									}
	ft_clear_objs(new);
	return (-1);
}

int	init_cylinder(char *line, int i, t_objs **objs)
{
	t_objs	*new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
						if ((i = base_parse(line, new, i, 2)) != -1)
							if ((i = ft_space(line, i, 1)) != -1)
								if (routine(&new->height,
									line, &i, 2) != -1)
									if ((i = ft_color(
									new->base->color, line, i)) != -1)
										if (ft_check_color_vdir(
											new->base->color, 2) != -1)
											if ((
											i = ft_space(line, i, 2)) != -1)
											{
												new->type = 4;
												new->next = *objs;
												*objs = new;
												return (i);
											}
	ft_clear_objs(new);
	return (-1);
}

int	init_triangle(char *line, int i, t_objs **objs)
{
	t_objs	*new;

	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((i = base_parse(line, new, i, 0)) != -1)
				if ((i = ft_coordonnees(new->base->origins, line, i)) != -1)
					if ((i = ft_coordonnees(new->p2, line, i)) != -1)
						if ((i = ft_coordonnees(new->p3, line, i)) != -1)
							if ((ft_vdir_tr(new->base, new->p2, new->p3)))
								if ((i = ft_color(new->base->color,
									line, i)) != -1)
									if (ft_check_color_vdir(
										new->base->color, 2) != -1)
									{
										new->type = 5;
										new->next = *objs;
										*objs = new;
										return (i);
									}
	ft_clear_objs(new);
	return (-1);
}
