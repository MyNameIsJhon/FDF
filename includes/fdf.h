/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:48:27 by jriga             #+#    #+#             */
/*   Updated: 2025/08/14 23:22:07 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define PADDING 100

#include "libft.h"

enum e_linux_key
{
	KEY_ESC     = 65307,
	KEY_ENTER   = 65293,
	KEY_SPACE   = 32,
	KEY_TAB     = 65289,
	KEY_BACKSP  = 65288,

	// Arrows
	KEY_LEFT    = 65361,
	KEY_UP      = 65362,
	KEY_RIGHT   = 65363,
	KEY_DOWN    = 65364,

	// Letters
	KEY_A       = 97,
	KEY_B       = 98,
	KEY_C       = 99,
	KEY_D       = 100,
	KEY_E       = 101,
	KEY_F       = 102,
	KEY_G       = 103,
	KEY_H       = 104,
	KEY_I       = 105,
	KEY_J       = 106,
	KEY_K       = 107,
	KEY_L       = 108,
	KEY_M       = 109,
	KEY_N       = 110,
	KEY_O       = 111,
	KEY_P       = 112,
	KEY_Q       = 113,
	KEY_R       = 114,
	KEY_S       = 115,
	KEY_T       = 116,
	KEY_U       = 117,
	KEY_V       = 118,
	KEY_W       = 119,
	KEY_X       = 120,
	KEY_Y       = 121,
	KEY_Z       = 122,

	// Digits (top row, no shift)
	KEY_0       = 48,
	KEY_1       = 49,
	KEY_2       = 50,
	KEY_3       = 51,
	KEY_4       = 52,
	KEY_5       = 53,
	KEY_6       = 54,
	KEY_7       = 55,
	KEY_8       = 56,
	KEY_9       = 57,

	// Symbols
	KEY_MINUS   = 45,   // "-"
	KEY_EQUAL   = 61,   // "=" (shift = "+")
	KEY_COMMA   = 44,   // ","
	KEY_DOT     = 46,   // "."
	KEY_SLASH   = 47,   // "/"
	KEY_SEMI    = 59,   // ";"
	KEY_APOST   = 39,   // "'"
	KEY_LBRACK  = 91,   // "["
	KEY_RBRACK  = 93,   // "]"
	KEY_BACKSL  = 92,   // "\"
};
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}			t_img;


typedef struct s_gradient
{
	int color_a;
	int	color_b;
}		t_gradient;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_pointd
{
	double	x;
	double	y;
}			t_pointd;

typedef struct s_pos
{
	t_point a;
	t_point b;
}			t_pos;

typedef struct s_loc
{
	int		altitude;
	int		color;
	t_point	point;
}			t_loc;

typedef struct s_map
{
	char 	***c_map;
	t_loc	**loc;
	t_pos	*position;
	int		cols;
	int		rows;
	int		width;
	int		height;
}			t_map;

typedef struct s_window
{
	int		width;
	int		height;
	int		padding;
	t_bool	state;
	t_point	offset;
	int		gap;
	double	zoom;
	double	var_alt;
} 			t_window;

typedef struct s_fdf 
{
	void		*mlx;
	void		*win;
	t_img		map;
	t_img		menu;
	t_window	*window;
	t_map		*data;
}			t_fdf;

typedef enum e_event
{
	ON_DESTROY = 17,
}			t_event;

void	map_get_dimensions(t_map *map, const char *file);
void put_pixel(t_img *img, int x, int y, int color);
void draw_line(t_img *img, t_point a, t_point b, int color);
void draw_vertical(t_fdf *env, t_point a, t_point b, int color);
void print_map(t_map *map);
t_map *init_map(const char *path, t_window *window);
void draw_map(t_img *img, t_map *map, t_window *window);
void	map_initzoom(t_window *window, t_map *map);
void map_offset(t_window *window, t_map *map);
void	fill_background(t_img *img, int color);

#endif
