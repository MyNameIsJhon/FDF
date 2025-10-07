/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:04:46 by jriga             #+#    #+#             */
/*   Updated: 2025/10/03 00:06:55 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mlx.h"
#include "fdf.h"
#include "fileft.h"
#include <stdlib.h>
#include <stdio.h>

static t_fdf	*init_env(t_map *map, t_window *window)
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF");
	env->map.ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->map.addr = mlx_get_data_addr(env->map.ptr, &env->map.bpp,
			&env->map.size_line, &env->map.endian);
	env->menu.ptr = mlx_new_image(env->mlx, 250, HEIGHT);
	env->menu.addr = mlx_get_data_addr(env->menu.ptr, &env->menu.bpp,
			&env->menu.size_line, &env->menu.endian);
	env->window = window;
	env->data = map;
	print_menu(env);
	return (env);
}

static t_map	*init_map(const char *path, t_window *window)
{
	t_map	*map;
	char	*file;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	file = get_file((char *)path);
	if (!file)
	{
		perror("Could not read file");
		free(map);
		exit(1);
		return (NULL);
	}
	window->var_alt = 1;
	map->cols = get_map_size(file).x;
	map->rows = get_map_size(file).y;
	init_zoom(window, map);
	map_offset(window);
	map->loc = read_map(file, window);
	ft_free(file);
	return (map);
}

#include "tests.h"

int	main(int ac, char **av)
{
	t_map		*map;
	t_fdf		*env;
	t_window	window;

	window.width = WIDTH;
	window.height = HEIGHT;
	window.padding = 100;
	if (ac != 2)
	{
		ft_puterror("Usage: ./fdf <map_file>\n");
		return (1);
	}
	map = init_map(av[1], &window);
	env = init_env(map, &window);
	if (!env || !map)
		exit_fdf(env);
	mlx_hook(env->win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->win, ON_DESTROY, 0, close_hook, env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}
