/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:35:36 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/06 02:12:35 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static int	gestion_win_deux(int keycode, t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	ft_clear(env->map);
	if (keycode == R_KEY)
	{
		start(env, 2);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		ft_clear(env->map);
	}
	exit(EXIT_SUCCESS);
	return (1);
}

static int	gestion_win(int keycode, t_env *env)
{
	t_map	*map;

	if (keycode == R_KEY || keycode == ESC_KEY)
		return (gestion_win_deux(keycode, env));
	if (keycode == N_KEY || keycode == P_KEY)
	{
		map = env->map;
		if (keycode == N_KEY)
			if (map->cams->next->next != NULL)
				map->cams = map->cams->next;
		if (keycode == P_KEY)
			if (map->cams->previous != NULL)
				map->cams = map->cams->previous;
		drop_ray(env);
		mlx_clear_window(env->mlx, env->mlx_win);
		mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	}
	return (1);
}

static int	ft_exit(t_env *env)
{
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	free(env->img.img);
	ft_clear(env->map);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	refresh(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	return (1);
}

int			mlx_gestion(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	mlx_key_hook(env->mlx_win, gestion_win, env);
	mlx_hook(env->mlx_win, MAPNOTIFY, STRUCTMASK, refresh, env);
	mlx_hook(env->mlx_win, DESTROY, STRUCTMASK, ft_exit, env);
	mlx_loop(env->mlx);
	return (1);
}
