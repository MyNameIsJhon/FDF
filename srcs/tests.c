/* #include <stdio.h> */
/**/
/* typedef enum e_event */
/* { */
/* 	ON_DESTROY = 17 */
/* }	t_event; */
/**/
/* typedef struct s_point */
/* { */
/* 	int	x; */
/* 	int	y; */
/* }	t_point; */
/**/
/* typedef struct s_pointd */
/* { */
/* 	double	x; */
/* 	double	y; */
/* }	t_pointd; */
/**/
/* typedef struct s_pos */
/* { */
/* 	t_point	a; */
/* 	t_point	b; */
/* }	t_pos; */
/**/
/* typedef struct s_rgb */
/* { */
/* 	int	r; */
/* 	int	g; */
/* 	int	b; */
/* }	t_rgb; */
/**/
/* typedef struct s_gradient */
/* { */
/* 	int	color_a; */
/* 	int	color_b; */
/* }	t_gradient; */
/**/
/* typedef struct s_img */
/* { */
/* 	void	*ptr; */
/* 	char	*addr; */
/* 	int		bpp; */
/* 	int		size_line; */
/* 	int		endian; */
/* 	int		w; */
/* 	int		h; */
/* }	t_img; */
/**/
/* typedef struct s_loc */
/* { */
/* 	int			altitude; */
/* 	int			color; */
/* 	t_point		point; */
/* 	t_point		iso; */
/* 	t_pointd	iso_t; */
/* }	t_loc; */
/**/
/* typedef struct s_map */
/* { */
/* 	t_loc	**loc; */
/* 	t_pos	*position; */
/* 	int		cols; */
/* 	int		rows; */
/* 	int		width; */
/* 	int		height; */
/* }	t_map; */

#include "fdf.h"
#include <stdio.h>

void print_s_map(t_map *map)
{
	printf("Map width: %d\n", map->width);
	printf("Map height: %d\n", map->height);
	printf("Map position a: (%d,%d)\n", map->position->a.x, map->position->a.y);
	printf("Map cols: %d\n", map->cols);
	printf("Map rows: %d\n", map->rows);
	for (int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->cols; j++)
		{
			printf("(%d,%d,%d) ", map->loc[i][j].altitude, map->loc[i][j].color, map->loc[i][j].point.x);
			printf("(%d,%d,%d) ", map->loc[i][j].point.y, map->loc[i][j].iso.x, map->loc[i][j].iso.y);
			printf("(%f,%f)\n", map->loc[i][j].iso_t.x, map->loc[i][j].iso_t.y);
		}
		printf("\n");
	}
}
