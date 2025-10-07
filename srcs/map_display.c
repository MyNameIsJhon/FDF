/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:15:19 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:45:02 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_iso(t_img *img, t_loc loc_a, t_loc loc_b)
{
	t_point		a;
	t_point		b;
	t_gradient	grad;

	b.x = loc_b.iso.x;
	b.y = loc_b.iso.y;
	a.x = loc_a.iso.x;
	a.y = loc_a.iso.y;
	if (loc_a.color == loc_b.color)
		draw_line(img, a, b, loc_a.color);
	else
	{
		grad.color_a = loc_a.color;
		grad.color_b = loc_b.color;
		draw_line_gradient(img, a, b, grad);
	}
}

static void	draw_rows(t_img *img, t_loc **loc, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols - 1)
		{
			draw_line_iso(img, loc[i][j], loc[i][j + 1]);
			j++;
		}
		i++;
	}
}

static void	draw_cols(t_img *img, t_loc **loc, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < cols)
	{
		j = 0;
		while (j < rows - 1)
		{
			draw_line_iso(img, loc[j][i], loc[j + 1][i]);
			j++;
		}
		i++;
	}
}

void	draw_map(t_img *img, t_map *map)
{
	t_loc	**loc;

	loc = map->loc;
	draw_rows(img, loc, map->rows, map->cols);
	draw_cols(img, loc, map->rows, map->cols);
}
