/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:16:44 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:37:09 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"
#include <errno.h>
#include <stdio.h>

int	close_window(void *param)
{
	t_fdf	*env;

	env = (t_fdf *)param;
	mlx_destroy_window(env->mlx, env->win);
	free(env);
	exit(0);
	return (0);
}

void	free_locs(t_map *map)
{
	int	y;

	y = 0;
	if (!map || !map->loc)
		return ;
	while (y < map->rows)
	{
		free(map->loc[y]);
		y++;
	}
	free(map->loc);
	map->loc = NULL;
}

void	exit_fdf(t_fdf *env)
{
	if (env->mlx)
	{
		if (env->map.ptr)
			mlx_destroy_image(env->mlx, env->map.ptr);
		if (env->menu.ptr)
			mlx_destroy_image(env->mlx, env->menu.ptr);
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	if (env->data)
	{
		free_locs(env->data);
		free(env->data);
	}
	free(env);
	exit(0);
}
