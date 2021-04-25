/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:16 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/25 22:04:24 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H
# include "../../minirt.h"

double				intersect_cy(t_triade ray, t_objs *ptr,
		t_triade *origins);
double				intersect_sphere(t_triade ray, t_objs *ptr,
		t_triade *origins);
double				intersect_plan(t_triade ray, t_objs *ptr,
		t_triade *origins);
double				ft_angle(t_triade *t1, t_triade *t2);
double				calcul_polynome(double x, double y, double z,
		int opt);
t_triade			get_color(t_ambiant *ambiant, t_lights *lights,
		t_objs *ptr, double intensity);
t_triade			get_position(t_triade *origins, t_triade ray,
		double t);
t_triade			get_normale(t_objs *ptr, t_triade position,
		t_map *map);
t_triade			*vector_v(t_triade *t1, t_triade *t2);
unsigned long int	interlplan(double t, t_triade ray, t_objs *ptr,
		t_map *map);
unsigned long int	interlsphere(double t, t_triade ray, t_objs *ptr,
		t_map *map);

#endif
