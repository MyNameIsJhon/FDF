/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 03:24:45 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:51:54 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fileft.h"
#include "fdf.h"

static t_loc	**loc_alloc(int rows, int cols)
{
	t_loc	**locs;
	int		i;

	locs = malloc(sizeof(t_loc *) * (rows + 1));
	if (!locs)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		locs[i] = malloc(sizeof(t_loc) * (cols + 1));
		if (!locs[i])
		{
			while (i > 0)
			{
				free(locs[i - 1]);
				i--;
			}
			free(locs);
			return (NULL);
		}
		i++;
	}
	locs[rows] = NULL;
	return (locs);
}

static void	set_locations_iso(t_loc *loc, t_window *win)
{
	double	cos;
	double	sin;

	sin = ISO_SIN;
	cos = ISO_COS;
	loc->iso_t.x = (loc->point.x - loc->point.y) * cos;
	loc->iso_t.y = (loc->point.x + loc->point.y) * sin;
	loc->iso.x = (int)(loc->iso_t.x * win->zoom + win->offset.x);
	loc->iso.y = (int)((loc->iso_t.y - (double)loc->altitude * win->var_alt)
			* win->zoom + win->offset.y);
}

static void	point_parser(char *buff, t_loc *loc)
{
	char	*v;

	loc->altitude = ft_atoi(buff);
	v = ft_strchr(buff, ',');
	if (v)
		loc->color = ft_atoi_hex(v + 1);
	else
		loc->color = 0xFFFFFF;
}

static void	get_locations(char **curs, t_loc **locs,
							t_point s_map, t_window *win)
{
	int		y;
	int		x;
	char	buff[50];

	y = 0;
	while (y < s_map.y)
	{
		x = 0;
		while (x < s_map.x)
		{
			*curs = read_to_charset(*curs, buff, " \n");
			point_parser(buff, &locs[y][x]);
			locs[y][x].point.x = x - ((s_map.x - 1) / 2);
			locs[y][x].point.y = y - ((s_map.y - 1) / 2);
			set_locations_iso(&locs[y][x], win);
			x++;
		}
		y++;
	}
}

t_loc	**read_map(char *file, t_window *win)
{
	t_point	s_map;
	t_loc	**locs;
	char	*curs;

	s_map = get_map_size(file);
	locs = loc_alloc(s_map.y, s_map.x);
	if (!locs)
		return (NULL);
	curs = file;
	get_locations(&curs, locs, s_map, win);
	return (locs);
}
