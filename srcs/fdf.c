#include "libft.h"
#include <fcntl.h>
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include "fileft.h"

/* void	chess_draw(t_fdf *env, t_point a, t_point b, int color) */
/* { */
/* 	t_point	ptr_a; */
/* 	t_point	ptr_b; */
/* 	int		dx; */
/* int		dy; */

/* dx = (b.x - a.x) / 10; */
/* dy = (b.y - a.y) / 10; */
/* ptr_a.y = a.y; */
/* ptr_b.y = a.y; */
/* ptr_a.x = a.x; */
/* ptr_b.x = b.x; */
/* while (ptr_a.y <= b.y) */
/* { */
/* 	draw_line(env, ptr_a, ptr_b, color); */
/* 	ptr_a.y += dy; */
/* 	ptr_b.y += dy; */
/* } */
/* 	ptr_a.x = a.x; */
/* 	ptr_b.x = a.x; */
/* 	ptr_a.y = a.y; */
/* 	ptr_b.y = b.y; */
/* 	while (ptr_a.x <= b.x) */
/* 	{ */
/* 		draw_line(env, ptr_a, ptr_b, color); */ /* 		ptr_a.x += dx; */
/* 		ptr_b.x += dx; */
/* 	} */
/* } */

int close_window(void *param)
{
	t_fdf *env;

	env = (t_fdf*)param;
	mlx_destroy_window(env->mlx, env->win);
	free(env);
	exit(0);
	return (0);
}

void free_env(t_fdf *env)
{
	if (env->mlx)
	{
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
		if (env->map.ptr)
			mlx_destroy_image(env->mlx, env->map.ptr);
		if (env->menu.ptr)
			mlx_destroy_image(env->mlx, env->menu.ptr);
	}
	free(env);
}

int key_hook(int keycode, void *param)
{
	t_fdf *env;
	env = (t_fdf*)param;

	if (keycode == KEY_ESC)
	{
		close_window(env);
		return (0);
	}
	else if (keycode == KEY_L)
		env->window->zoom *= 0.99;
	else if (keycode == KEY_M)
		env->window->zoom *= 1.01;
	else if (keycode == KEY_RIGHT)
		env->window->offset.x += 3;
	else if (keycode == KEY_LEFT)
		env->window->offset.x -= 3;
	else if (keycode == KEY_DOWN)
		env->window->offset.y += 3;
	else if (keycode == KEY_UP)
		env->window->offset.y -= 3;
	else if (keycode == KEY_A)
		env->window->var_alt *= 1.01;
	else if (keycode == KEY_B)
		env->window->var_alt *= 0.99;
	else if (keycode == KEY_R)
	{
		env->window->var_alt = 1.0;
		map_initzoom(env->window, env->data);
		map_offset(env->window, env->data);
	}
	return (0);
}

static int render(t_fdf *env)
{
	fill_background(&env->map, 0x000000);
	draw_map(&env->map, env->data, env->window);
	mlx_put_image_to_window(env->mlx, env->win, env->map.ptr, 200, 0);
	return (0);
}

int main(int ac, char **av)
{
	t_map	*map;
	/* int color; */
	t_fdf	*env; 
	t_window window;
	/* color = 0xFF0000; */
	window.width = WIDTH;
	window.height = HEIGHT;
	window.padding = 100;
	if (ac < 2)
		return (1);
	map = init_map(av[1], &window);
	env = (t_fdf*)malloc(sizeof (t_fdf));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "hello world");
	env->map.ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->map.addr = mlx_get_data_addr(env->map.ptr, &env->map.bpp, &env->map.size_line, &env->map.endian);
	env->menu.ptr = mlx_new_image(env->mlx, 200, HEIGHT);
	env->menu.addr = mlx_get_data_addr(env->menu.ptr, &env->menu.bpp, &env->menu.size_line, &env->menu.endian);
	env->window = &window;
	env->data = map;
	fill_background(&env->menu, 0xFFFFFF);
	mlx_put_image_to_window(env->mlx, env->win, env->menu.ptr, 0, 0);
	mlx_string_put(env->mlx, env->win, 10, 30, 0x000000, "FDF commands:");
	mlx_string_put(env->mlx, env->win, 10, 50, 0x000000, "Press ESC to exit");
	mlx_string_put(env->mlx, env->win, 10, 70, 0x000000, "Press R to reset");
	mlx_string_put(env->mlx, env->win, 10, 90, 0x000000, "Press L to zoom out");
	mlx_string_put(env->mlx, env->win, 10, 110, 0x000000, "Press M to zoom in");
	mlx_string_put(env->mlx, env->win, 10, 130, 0x000000, "Press A to increase altitude");
	mlx_string_put(env->mlx, env->win, 10, 150, 0x000000, "Press B to decrease altitude");
	mlx_string_put(env->mlx, env->win, 10, 170, 0x000000, "Press arrows to move the map");
	mlx_hook(env->win, 2, 1L<<0, key_hook, env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	(void)map;
	return (0);
}
