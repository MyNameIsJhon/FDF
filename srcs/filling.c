/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:48:36 by jriga             #+#    #+#             */
/*   Updated: 2025/09/07 21:19:00 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_background(t_img *img, int color)
{
	int	x;
	int	y;

	if (!img->addr)
		return ;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	fill_background_grad(t_img *img, t_gradient grad)
{
	int	x;
	int	y;
	int	color;

	if (!img->addr)
		return ;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = color_at_step(grad, x + y, WIDTH + HEIGHT);
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}
