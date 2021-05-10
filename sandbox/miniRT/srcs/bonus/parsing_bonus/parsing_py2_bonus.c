/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_py2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 01:08:14 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/09 02:12:51 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"



int test(t_objs *tr, t_triade p[5], t_objs *py, int opt)
{

  if ()
  if (new_tr(&tr[0], p[0], p[1], p[3], py))
    if (new_tr(&tr[1], p[0], p[2], p[1], py))
      if (new_tr(&tr[2], p[0], p[2], p[4], py))
        if (new_tr(&tr[3], p[0], p[4], p[3], py))
          if (new_tr(&tr[4], p[4], p[2], p[1], py))
            if (new_tr(&tr[5], p[4], p[3], p[4], py))
            {
              tr[0]->next = tr[1];
              tr[1]->next = tr[2];
              tr[2]->next = tr[3];
              tr[3]->next = tr[4];
              tr[4]->next = tr[5];
              tr[5]->next = **objs;
              **objs = tr[0];
              return (1);
            }
  return (-1);
}

int news_objs2(t_objs **tr, t_triade p[6], t_objs *py, int opt)
{
	t_triade e[3];

	if (opt <= 4)
		e[0] = p[0];
	else if (opt == 5)
		e[0] = p[4];
	else
		e[0] = p[1];
	if (opt == 1)
		e[1] = p[1];
	else if (opt == 2 || opt == 3 || opt == 5)
		e[1] = p[2];
	else if (opt == 6)
		e[1] = p[3];
	else if (opt == 4)
		e[1] = p[4];
	if (opt == 2 || opt == 5)
		e[2] = p[1];
	else if (opt == 6)
		e[2] = p[4];
	else if (opt == 1 || opt == 4)
		e[2] = p[3];
	else if (opt == 3)
		e[2] = p[4];
	if ((new_tr(&tr, e, py)))
		return (1);
	return (-1);
}

int	news_objs(t_objs *py, t_objs ***objs)
{
	t_objs		*tr[6];
	t_base		*base;
	t_triade	p[6];
	t_triade	vdir[3];

	base = py->base;
	points_calcul(py, p, vdir, base);
	if (news_objs2(&tr[0], p, py, 1))
		if (news_objs2(&tr[1], p, py, 2))
			if (news_objs2(&tr[2], p, py, 3))
				if (news_objs2(&tr[3], p, py, 4))
					if (news_objs2(&tr[4], p, py, 5))
						if (news_objs2(&tr[5], p, py, 6))
						{
							tr[0]->next = tr[1];
							tr[1]->next = tr[2];
							tr[2]->next = tr[3];
							tr[3]->next = tr[4];
							tr[4]->next = tr[5];
							tr[5]->next = **objs;
							**objs = tr[0];
							return (1);
						}
	return (-1);
}

int init_py2(char *line, int i)
{
	if (ft_check_color_vdir(py->vdir2, 1) != -1)
		if ((i = ft_space(line, i, 1)) != -1)
			if (routine(&py->height, line, &i, 2) != -1)
				if ((i = ft_space(line, i, 1)) != -1)
					if (routine(&py->diam, line, &i, 2) != -1)
						if ((i = ft_color(py->base->color, line, i)) != -1)
							if (ft_check_color_vdir(py->base->color, 2) != -1)
								if ((i = ft_space(line, i, 2)) != -1)
									return (i);
		return (-1);
}

int	init_py(char *line, int i, t_objs **objs)
{
	t_objs	*py;

	if ((py = ft_calloc(1, sizeof(t_objs))))
		if ((py->base = ft_calloc(1, sizeof(t_base))))
			if ((py->base->origins = ft_calloc(1, sizeof(t_triade))))
				if ((py->base->vdir = ft_calloc(1, sizeof(t_triade))))
					if ((py->vdir2 = ft_calloc(1, sizeof(t_triade))))
						if ((py->base->color = ft_calloc(1, sizeof(t_triade))))
							if ((i = base_parse(line, py, i, 1)) != -1)
								if ((i = ft_structuration(py->vdir2, line, i)) != -1)
									if ((i = init_py2(line, i)) != -1)
									{
										news_objs(py, &objs);
										ft_clear_objs(py);
										return (i);
									}
	ft_clear_objs(py);
	return (-1);
}
