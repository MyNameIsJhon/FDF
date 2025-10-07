/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 03:02:24 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:44:03 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <libft.h>
#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	bpp_bytes;
	int	offset;

	bpp_bytes = img->bpp / 8;
	offset = y * img->size_line + x * bpp_bytes;
	if (!img->addr || bpp_bytes <= 0)
		return ;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	if (img->endian == 0)
	{
		img->addr[offset + 0] = (color) & 0xFF;
		img->addr[offset + 1] = (color >> 8) & 0xFF;
		img->addr[offset + 2] = (color >> 16) & 0xFF;
		img->addr[offset + 3] = 0;
	}
	else
	{
		img->addr[offset + 0] = (color >> 24) & 0xFF;
		img->addr[offset + 1] = (color >> 16) & 0xFF;
		img->addr[offset + 2] = (color >> 8) & 0xFF;
		img->addr[offset + 3] = (color) & 0xFF;
	}
}

void	draw_line(t_img *img, t_point a, t_point b, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = ft_icmp(a.x, b.x);
	s.y = ft_icmp(a.y, b.y);
	err = d.x - d.y;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel(img, a.x, a.y, color);
		e2 = 2 * err;
		if (e2 > -d.y)
		{
			err -= d.y;
			a.x += s.x;
		}
		if (e2 < d.x)
		{
			err += d.x;
			a.y += s.y;
		}
	}
}
