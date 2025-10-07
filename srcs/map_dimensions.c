/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:49:17 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:54:58 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	map_init_usable(t_window *win, t_map *map,
							int *usable_w, int *usable_h)
{
	*usable_w = win->width - 2 * win->padding;
	*usable_h = win->height - 2 * win->padding;
	if (*usable_w <= 0)
		*usable_w = win->width;
	if (*usable_h <= 0)
		*usable_h = win->height;
	if (map->cols <= 0 || map->rows <= 0)
	{
		win->zoom = 1;
		map->width = 0;
		map->height = 0;
		return (0);
	}
	return (1);
}

void	init_zoom(t_window *win, t_map *map)
{
	int	usable_w;
	int	usable_h;
	int	zx;
	int	zy;
	int	z;

	if (!map_init_usable(win, map, &usable_w, &usable_h))
		return ;
	zx = usable_w / map->cols;
	zy = usable_h / map->rows;
	if (zx < zy)
		z = zx;
	else
		z = zy;
	if (z > 1)
		z -= 1;
	if (z < 1)
		z = 1;
	win->zoom = z - z / 8;
	map->width = win->zoom * map->cols;
	map->height = win->zoom * map->rows;
}

void	map_offset(t_window *window)
{
	int	usable_w;
	int	usable_h;

	usable_w = window->width - 2 * window->padding;
	usable_h = window->height - 2 * window->padding;
	if (usable_w < 0)
		usable_w = window->width;
	if (usable_h < 0)
		usable_h = window->height;
	window->offset.x = window->padding + usable_w / 2;
	window->offset.y = window->padding + usable_h / 2;
}

static void	update_line_size(t_point *size, int *x)
{
	if (*x > size->x)
		size->x = *x;
	size->y++;
	*x = 0;
}

static void	parse_map_size(const char *file, t_point *size)
{
	int	i;
	int	x;
	int	in_value;

	i = 0;
	x = 0;
	in_value = 0;
	while (file[i])
	{
		if (file[i] != ' ' && file[i] != '\n' && !in_value)
		{
			in_value = 1;
			x++;
		}
		if (file[i] == ' ' || file[i] == '\n')
			in_value = 0;
		if (file[i] == '\n')
			update_line_size(size, &x);
		i++;
	}
	if (x > 0)
		update_line_size(size, &x);
}

t_point	get_map_size(const char *file)
{
	t_point	size;

	if (!file)
		return ((t_point){0, 0});
	size.x = 0;
	size.y = 0;
	parse_map_size(file, &size);
	return (size);
}
