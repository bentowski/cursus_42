#include "minirt.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int handle_key(int keycode, t_env *env)
{
  if (keycode == SPC_KEY)
	 mlx_clear_window(env->mlx, env->mlx_win);
  else if (keycode == ESC_KEY)
  {
    mlx_destroy_window(env->mlx, env->mlx_win);
    free(env->mlx);
    exit(EXIT_SUCCESS);
    system("leaks a.out");
  }
	return (1);
}

int main(int argc, char **argv)
{
	t_env env;
	double x;
	double y;

	env.mlx = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx, 800, 400, "Hello world");
	env.img.img = mlx_new_image(env.mlx, 800, 400);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
  y = -1;
	while (y++ < 400 - 1)
	{
		x = -1;
		while (x++ < 800 - 1)
		{
      my_mlx_pixel_put(&env.img, x, y, 0xFF0000);
		}
	}
	mlx_put_image_to_window(env.mlx, env.mlx_win, env.img.img, 0, 0);
	// mlx_mouse_hook(env.mlx_win, &test, &env);
  // mlx_hook_lopp()
  // mlx_clear_window(env.mlx, env.mlx_win);
  mlx_key_hook(env.mlx_win, handle_key, &env);
	mlx_loop(env.mlx);
  return (1);
}

// int		handle_key(int keycode, t_mlx *vars)
// {
// 	if (keycode == SPC_KEY)
// 	{
// 		vars->imgs = vars->imgs->next;
// 		mlx_put_image_to_window(vars->mlx, vars->win,
// 			(*(t_data *)vars->imgs->content).img, 0, 0);
// 		return (1);
// 	}
// 	if (keycode == ESC_KEY)
// 	{
// 		free_imgs(vars);
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		if (OS == 2)
// 			mlx_destroy_display(vars->mlx);
// 		free(vars->mlx);
// 		exit(EXIT_SUCCESS);
// 	}
// 	return (1);
// }
//
// mlx_put_image_to_window(s.mlx, s.win.ptr, s.img.ptr, 0, 0);
//     mlx_hook(s.win.ptr, 2, 1L, &ft_keypress, &s);
//     mlx_hook(s.win.ptr, 3, 2L, &ft_keyrelease, &s);
//     mlx_hook(s.win.ptr, 17, 1L << 17, &ft_exit, &s);
//     mlx_hook(s.win.ptr, 33, 1L << 17, &ft_exit, &s);
//     mlx_expose_hook(s.win.ptr, &ft_display, &s);
//     mlx_loop_hook(s.mlx, &ft_move, &s);
//     mlx_loop(s.mlx);
