/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 03:02:24 by jriga             #+#    #+#             */
/*   Updated: 2025/08/15 04:38:09 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <libft.h>
#include "fdf.h"

void put_pixel(t_img *img, int x, int y, int color)
{
	int bpp_bytes;
	int offset;

	bpp_bytes  = img->bpp / 8;
	offset = y * img->size_line + x * bpp_bytes;
	if (!img->addr || bpp_bytes <= 0) 
		return;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) 
		return;
	if (img->endian == 0)
	{
		img->addr[offset + 0] = (color      ) & 0xFF;
		img->addr[offset + 1] = (color >> 8 ) & 0xFF;
		img->addr[offset + 2] = (color >> 16) & 0xFF;
		img->addr[offset + 3] = 0;
	}
	else 
	{
		img->addr[offset + 0] = (color >> 24) & 0xFF;
		img->addr[offset + 1] = (color >> 16) & 0xFF;
		img->addr[offset + 2] = (color >> 8 ) & 0xFF;
		img->addr[offset + 3] = (color      ) & 0xFF;
	}
}

int	get_gradient(int color_a, int color_b, double t)
{
	int	r;
	int	g;
	int	b;

	if (t < 0.0)
		t = 0.0;
	if (t > 1.0)
		t = 1.0;
	r = ((color_a >> 16) & 0xFF)
		+ (((color_b >> 16) & 0xFF) - ((color_a >> 16) & 0xFF)) * t;
	g = ((color_a >> 8) & 0xFF)
		+ (((color_b >> 8) & 0xFF) - ((color_a >> 8) & 0xFF)) * t;
	b = (color_a & 0xFF)
		+ ((color_b & 0xFF) - (color_a & 0xFF)) * t;
	return ((r << 16) | (g << 8) | b);
}

int	compare(int a, int b)
{
	if (a < b)
		return (1);
	else if (a > b)
		return (-1);
	return (0);
}

void draw_line(t_img *img, t_point a, t_point b, int color)
{
	t_point d;
	t_point s;
	int	err;
	int		e2;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = compare(a.x, b.x);
	s.y = compare(a.y, b.y);
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

static int	maxi(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	lerp8(int a, int b, int step, int steps)
{
	long	num;

	if (steps <= 0)
		return (a);
	num = (long)(b - a) * (long)step;
	return (a + (int)(num / (long)steps));
}

static int	color_at_step(t_gradient g, int step, int steps)
{
	int	ra;
	int	ga;
	int	ba;
	int	rb;
	int	gb;
	int	bb;
	int	r;
	int	gc;
	int	b;

	ra = (g.color_a >> 16) & 0xFF;
	ga = (g.color_a >> 8) & 0xFF;
	ba = g.color_a & 0xFF;
	rb = (g.color_b >> 16) & 0xFF;
	gb = (g.color_b >> 8) & 0xFF;
	bb = g.color_b & 0xFF;
	r = lerp8(ra, rb, step, steps);
	gc = lerp8(ga, gb, step, steps);
	b = lerp8(ba, bb, step, steps);
	return ((r << 16) | (gc << 8) | b);
}

static void	bres_step(t_point *p, t_point d, t_point s, int *err)
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
	int		steps;
	int		step;
	t_point	cur;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = compare(a.x, b.x);
	s.y = compare(a.y, b.y);
	err = d.x - d.y;
	steps = maxi(d.x, d.y);
	step = 0;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel(img, cur.x, cur.y, color_at_step(grad, step, steps));
		bres_step(&cur, d, s, &err);
		step++;
	}
	put_pixel(img, b.x, b.y, grad.color_b);
}

void	map_initzoom(t_window *win, t_map *map)
{
	int	usable_w;
	int	usable_h;
	int	zx;
	int	zy;
	int	z;

	usable_w = win->width - 2 * win->padding;
	usable_h = win->height - 2 * win->padding;
	if (usable_w <= 0)
		usable_w = win->width;
	if (usable_h <= 0)
		usable_h = win->height;
	if (map->cols <= 0 || map->rows <= 0)
	{
		win->zoom = 1;
		map->width = 0;
		map->height = 0;
		return ;
	}
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
	win->zoom = z;
	map->width = win->zoom * map->cols;
	map->height = win->zoom * map->rows;
}



void	map_offset(t_window *window, t_map *map)
{
	int usable_w;
	int usable_h;

	(void)map;
	usable_w = window->width - 2 * window->padding;
	usable_h = window->height - 2 * window->padding;
	if (usable_w < 0) 
		usable_w = window->width;
	if (usable_h < 0)
		usable_h = window->height;
	window->offset.x = window->padding + usable_w / 2;
	window->offset.y = window->padding + usable_h / 2;
}

void	draw_line_iso(t_img *img, t_loc *a, t_loc *b,
				   t_window *win, int angle)
{
	double	rad;
	double	c;
	double	s;
	double	ax;
	double	ay;
	double	bx;
	double	by;
	t_point	pa;
	t_point	pb;
	t_gradient gradient;

	rad = (double)angle * FT_PI / 180.0;
	c = ft_cos(rad);
	s = ft_sin(rad);
	ax = (a->point.x - a->point.y) * c;
	ay = (a->point.x + a->point.y) * s - (double)a->altitude * win->var_alt;
	bx = (b->point.x - b->point.y) * c;
	by = (b->point.x + b->point.y) * s - (double)b->altitude * win->var_alt;
	pa.x = (int)(ax * win->zoom + win->offset.x);
	pa.y = (int)(ay * win->zoom + win->offset.y);
	pb.x = (int)(bx * win->zoom + win->offset.x);
	pb.y = (int)(by * win->zoom + win->offset.y);
	gradient.color_a = a->color;
	gradient.color_b = b->color;
	if (a->color != b->color)
		draw_line_gradient(img, pa, pb, gradient);
	else
		draw_line(img, pa, pb, a->color);
}

void draw_rec(t_img *img, t_point a, t_point b, int color)
{
	t_point	c;
	t_point	d;
	c.x = b.x;
	c.y = a.y;
	d.x = a.x;
	d.y = b.y;
	draw_line(img, a, c, color);
	draw_line(img, c, b, color);
	draw_line(img, b, d, color);
	draw_line(img, d, a, color);
}

void	fill_background(t_img *img, int color)
{
	int	x;
	int	y;

	if (!img->addr)
		return;
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

void fill_background_grad(t_img *img, t_gradient grad)
{
	int	x;
	int	y;
	int	color;
	if (!img->addr)
		return;
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

void draw_map(t_img *img, t_map *map, t_window *window)
{
	t_loc	**loc;
	int		i;
	int 	j;

	loc = map->loc;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols - 1)
		{
			draw_line_iso(img, &loc[i][j], &loc[i][j + 1], window, 30);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		j = 0;
		while (j < map->rows - 1)
		{
			draw_line_iso(img, &loc[j][i], &loc[j + 1][i], window, 30);
			j++;
		}
		i++;
	}
}

/* void draw_chess(t_fdf *env, t_point a, t_point b, int color) */
/* { */
/**/
/* } */
