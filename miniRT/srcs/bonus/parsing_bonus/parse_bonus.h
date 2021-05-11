/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:02 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/11 15:40:45 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H
# include "../minirt_bonus.h"

int init_sphere(char *line, int i, t_objs **objs);
int init_plane(char *line, int i, t_objs **objs);
int init_square(char *line, int i, t_objs **objs);
int init_cylinder(char *line, int i, t_objs **objs);
int init_triangle(char *line, int i, t_objs **objs);
int ft_coordonnees(t_triade *new, char *line, int i);
int ft_structuration(t_triade *new, char *line, int i);
int ft_space(char *line, int i, int opt);
int ft_color(t_triade *color, char *line, int i);
int routine(double *x, char *line, int *i, int opt);
int res(char *line, int i, t_res **res);
int ambiance(char *line, int i, t_ambiant **ambiant);
int camera(char *line, int i, t_cams **cams);
int light(char *line, int i, t_lights **lights);
int foisdeux(char *line, int *ayet, int *ryet);
int ft_check_color_vdir(t_triade *check, int opt);
int base_parse(char *line, t_objs *new, int i, int opt);
int ft_vdir_tr(t_base *ptr, t_triade *p2, t_triade *p3);
int init_py(char *line, int i, t_objs **objs);
int news_objs2(t_objs **tr, t_triade p[6], t_objs *py, int opt);
int init_cu(char *line, int i, t_objs **objs);

#endif
