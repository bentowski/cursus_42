/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils_mov_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:31:42 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/10 06:27:55 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

static void	ft_rotate(int k, t_env *env)
{
	t_cams		*cam;
	t_triade	test;
	t_triade	n;
	t_triade	vdir;

	cam = env->map->cams;
	vdir = *cam->base->vdir;
	if (k == D_KEY)
		n = (t_triade){0, 1, 0};
	if (k == A_KEY)
		n = (t_triade){0, -1, 0};
	if (k == W_KEY)
		n = (t_triade){-1, 0, 0};
	if (k == S_KEY)
		n = (t_triade){1, 0, 0};
	test.x = n.y * vdir.z - n.z * vdir.y;
	test.y = n.z * vdir.x - n.x * vdir.z;
	test.z = n.x * vdir.y - n.y * vdir.x;
	if (vdir.x < 1 && vdir.x > -1)
		cam->base->vdir->x -= test.x * 0.05;
	if (vdir.y < 1 && vdir.y > -1)
		cam->base->vdir->y -= test.y * 0.05;
	if (vdir.z < 1 && vdir.z > -1)
		cam->base->vdir->z -= test.z * 0.05;
}

static void	ft_translate(int k, t_env *env)
{
	t_cams		*cam;
	t_triade	test;
	t_triade	n;
	t_triade	vdir;

	cam = env->map->cams;
	vdir = *cam->base->vdir;
	if (k == RARROW_KEY)
		n = (t_triade){0, 1, 0};
	if (k == LARROW_KEY)
		n = (t_triade){0, -1, 0};
	if (k == UARROW_KEY)
		n = (t_triade){-1, 0, 0};
	if (k == DARROW_KEY)
		n = (t_triade){1, 0, 0};
	test.x = n.y * vdir.z - n.z * vdir.y;
	test.y = n.z * vdir.x - n.x * vdir.z;
	test.z = n.x * vdir.y - n.y * vdir.x;
	test = get_norme(test);
	cam->base->origins->x -= test.x * 15;
	cam->base->origins->y -= test.y * 15;
	cam->base->origins->z -= test.z * 15;
}

int			gestion_win_trois(int k, t_env *env)
{
	if (k >= 65361 && k <= 65364)
		ft_translate(k, env);
	if (k == A_KEY || k == W_KEY || k == S_KEY || k == D_KEY)
		ft_rotate(k, env);
	drop_ray(env);
	mlx_clear_window(env->mlx, env->mlx_win);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	return (1);
}
