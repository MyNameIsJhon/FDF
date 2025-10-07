/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:49:21 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:44:28 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	step_at_color(int a, int b, int step, int steps)
{
	long	num;

	if (steps <= 0)
		return (a);
	num = (long)((b - a) * step);
	return (a + (int)(num / (long)steps));
}

int	color_at_step(t_gradient g, int step, int steps)
{
	t_rgb	a;
	t_rgb	b;
	t_rgb	c;

	a.r = (g.color_a >> 16) & 0xFF;
	a.g = (g.color_a >> 8) & 0xFF;
	a.b = g.color_a & 0xFF;
	b.r = (g.color_b >> 16) & 0xFF;
	b.g = (g.color_b >> 8) & 0xFF;
	b.b = g.color_b & 0xFF;
	c.r = step_at_color(a.r, b.r, step, steps);
	c.g = step_at_color(a.g, b.g, step, steps);
	c.b = step_at_color(a.b, b.b, step, steps);
	return ((c.r << 16) | (c.g << 8) | c.b);
}

void	bres_step(t_point *p, t_point d, t_point s, int *err)
{
	int	e2;

	e2 = *err << 1;
	if (e2 > -d.y)
	{
		*err -= d.y;
		p->x += s.x;
	}
	if (e2 < d.x)
	{
		*err += d.x;
		p->y += s.y;
	}
}

void	draw_line_gradient(t_img *img, t_point a, t_point b, t_gradient grad)
{
	t_point	d;
	t_point	s;
	int		err;
	t_load	ld;
	t_point	cur;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = ft_icmp(a.x, b.x);
	s.y = ft_icmp(a.y, b.y);
	err = d.x - d.y;
	ld.size = ft_max(d.x, d.y);
	ld.curs = 0;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel(img, cur.x, cur.y, color_at_step(grad, ld.curs, ld.size));
		bres_step(&cur, d, s, &err);
		ld.curs++;
	}
	put_pixel(img, b.x, b.y, grad.color_b);
}
