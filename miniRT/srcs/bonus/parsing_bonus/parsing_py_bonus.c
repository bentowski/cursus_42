/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_py_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:29:45 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/07 01:26:04 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int new_sq(t_objs **ret, t_base *base, double height, double size)
{
	t_objs *new;
	t_triade vdir;

	vdir = *base->vdir;
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
						new->base->origins->x = base->origins->x - (vdir.x * (height / 2));
						new->base->origins->y = base->origins->y - (vdir.y * (height / 2));
						new->base->origins->z = base->origins->z - (vdir.z * (height / 2));
						new->base->color->x = base->color->x;
						new->base->color->y = base->color->y;
						new->base->color->z = base->color->z;
						new->height = size;
						printf("%f\n", new->height);
						*ret = new;
						return (1);
					}
	ft_clear_objs(new);
	return (-1);
}

/*
int new_tr(t_objs **ret, t_base *base, double height, double size)
{
  t_objs *new;
  t_triade vdir;
  t_triade n;
  t_triade test;


  vdir = *base->vdir;
  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
      if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
        if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
          if ((new->p2 = ft_calloc(1, sizeof(t_triade))))
            if ((new->p3 = ft_calloc(1, sizeof(t_triade))))
              if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
              {
                new->type = 5;
                vdir = get_norme(vdir);
                new->base->origins->x = base->origins->x + (vdir.x * (height / 2));
                new->base->origins->y = base->origins->y + (vdir.y * (height / 2));
                new->base->origins->z = base->origins->z + (vdir.z * (height / 2));
                n = (t_triade){0, 0, 1};
                test.x = n.y * vdir.z - n.z * vdir.y;
              	test.y = n.z * vdir.x - n.x * vdir.z;
              	test.z = n.x * vdir.y - n.y * vdir.x;
                test = get_norme(test);
                size = size / 2;
                new->p2->x = (base->origins->x - (vdir.x * (height))) - (test.x * (size));
                new->p2->y = (base->origins->y - (vdir.y * (height))) - (test.y * (size));
                new->p2->z = (base->origins->z - (vdir.z * (height))) - (test.z * (size));
                new->p3->x = (base->origins->x - (vdir.x * (height))) - (test.x * (size));
                new->p3->y = (base->origins->y - (vdir.y * (height))) - (test.y * (size));
                new->p3->z = (base->origins->z - (vdir.z * (height))) - (test.z * (size));
                n = (t_triade){1, 0, 0};
                test.x = n.y * vdir.z - n.z * vdir.y;
                test.y = n.z * vdir.x - n.x * vdir.z;
                test.z = n.x * vdir.y - n.y * vdir.x;
                test = get_norme(test);
                new->p2->x -= (test.x * (size));
                new->p2->y -= (test.y * (size));
                new->p2->z -= (test.z * (size));
                new->p3->x += (test.x * (size));
                new->p3->y += (test.y * (size));
                new->p3->z += (test.z * (size));
                new->base->color->x = base->color->x;
                new->base->color->y = base->color->y;
                new->base->color->z = base->color->z;
                if (!(ft_vdir_tr(new->base, new->p2, new->p3)))
                  return (-1);
                *ret = new;
                printf("%f,%f,%f\n", new->base->origins->x, new->base->origins->y, new->base->origins->z);
                printf("%f,%f,%f\n", new->p2->x, new->p2->y, new->p2->z);
                printf("%f,%f,%f\n", new->p3->x, new->p3->y, new->p3->z);
                return (1);
              }
    ft_clear_objs(new);
    return (-1);
}
*/

int	new_sq2(t_objs **ret, t_base *base, double height, double size)
{
	t_objs		*new;
	t_triade	vdir;
	t_triade	n;
	t_triade	test;

	vdir = *base->vdir;
	if ((new = ft_calloc(1, sizeof(t_objs))))
		if ((new->base = ft_calloc(1, sizeof(t_base))))
			if ((new->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((new->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((new->base->color = ft_calloc(1, sizeof(t_triade))))
					{
						new->type = 2;
						n = (t_triade){1, 0, 0};
						test.x = n.y * vdir.z - n.z * vdir.y;
						test.y = n.z * vdir.x - n.x * vdir.z;
						test.z = n.x * vdir.y - n.y * vdir.x;
						new->base->vdir->x = test.x;
						new->base->vdir->y = test.y;
						new->base->vdir->z = test.z;
						vdir = get_norme(vdir);
						new->base->origins->x = base->origins->x - (test.x * (height / 2));
						new->base->origins->y = base->origins->y - (test.y * (height / 2));
						new->base->origins->z = base->origins->z - (test.z * (height / 2));
						new->base->color->x = base->color->x;
						new->base->color->y = base->color->y;
						new->base->color->z = base->color->z;
						new->height = size;
						printf("%f\n", new->height);
						*ret = new;
						return (1);
					}
	ft_clear_objs(new);
	return (-1);
}

int	news_objs(t_objs *py, t_base *base, t_objs ***objs)
{
	t_objs	*sq;
	t_objs	*sq2;

	new_sq(&sq, base, py->height, py->diam);
	new_sq2(&sq2, base, py->height, py->diam);
	sq->next = sq2;
	sq2->next = **objs;
	**objs = sq;
	return (1);
}

int	init_py(char *line, int i, t_objs **objs)
{
	t_objs	*py;

	if ((py = ft_calloc(1, sizeof(t_objs))))
		if ((py->base = ft_calloc(1, sizeof(t_base))))
			if ((py->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((py->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((py->base->color = ft_calloc(1, sizeof(t_triade))))
						if ((i = base_parse(line, py, i, 2)) != -1)
							if ((i = ft_space(line, i, 1)) != -1)
								if (routine(&py->height, line, &i, 2) != -1)
									if ((i = ft_color(py->base->color, line, i)) != -1)
										if (ft_check_color_vdir(py->base->color, 2) != -1)
											if ((i = ft_space(line, i, 2)) != -1)
											{
												news_objs(py, py->base, &objs);
												ft_clear_objs(py);
												return (i);
											}
	ft_clear_objs(py);
	return (-1);
}
