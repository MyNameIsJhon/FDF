/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:14:53 by jriga             #+#    #+#             */
/*   Updated: 2025/10/06 14:07:21 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h> 

void	change_locs(t_window *window, t_map *map)
{
	t_loc		**loc;
	int			x;
	int			y;
	double		zoom;
	t_pointd	off;

	loc = map->loc;
	zoom = window->zoom;
	off.x = window->offset.x;
	off.y = window->offset.y;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			loc[y][x].iso.x = (int)(loc[y][x].iso_t.x * zoom + off.x);
			loc[y][x].iso.y = (int)((loc[y][x].iso_t.y
						- (double)loc[y][x].altitude * window->var_alt)
					* zoom + off.y);
			x++;
		}
		y++;
	}
}

void	reset_view(t_fdf *env)
{
	env->window->var_alt = 1.0;
	init_zoom(env->window, env->data);
	map_offset(env->window);
}

int	key_hook(int keycode, void *param)
{
	t_fdf	*env;

	env = (t_fdf *)param;
	if (keycode == KEY_ESC)
		exit_fdf(env);
	else if (keycode == KEY_MINUS)
		env->window->zoom *= 0.99;
	else if (keycode == KEY_EQUAL)
		env->window->zoom *= 1.01;
	else if (keycode == KEY_RIGHT)
		env->window->offset.x += 3;
	else if (keycode == KEY_LEFT)
		env->window->offset.x -= 3;
	else if (keycode == KEY_DOWN)
		env->window->offset.y += 3;
	else if (keycode == KEY_UP)
		env->window->offset.y -= 3;
	else if (keycode == KEY_W)
		env->window->var_alt *= 1.01;
	else if (keycode == KEY_S)
		env->window->var_alt *= 0.99;
	else if (keycode == KEY_R)
		reset_view(env);
	change_locs(env->window, env->data);
	return (0);
}

int	render(t_fdf *env)
{
	fill_background(&env->map, 0x000000);
	draw_map(&env->map, env->data);
	mlx_put_image_to_window(env->mlx, env->win, env->map.ptr, 250, 0);
	return (0);
}

int	close_hook(void *param)
{
	t_fdf	*env;

	env = (t_fdf *)param;
	exit_fdf(env);
	return (0);
}
