/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:49:28 by jriga             #+#    #+#             */
/*   Updated: 2025/10/06 14:06:50 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

# define WIDTH        1280
# define HEIGHT       720
# define PADDING      100
# define ISO_ANGLE    0.5235987755982988
# define ISO_SIN      0.5
# define ISO_COS      0.8660254037844386

enum e_linux_key
{
	KEY_ESC = 65307,
	KEY_ENTER = 65293,
	KEY_SPACE = 32,
	KEY_TAB = 65289,
	KEY_BACKSP = 65288,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_PLUS = 43,
	KEY_MINUS = 45,
	KEY_EQUAL = 61,
	KEY_COMMA = 44,
	KEY_DOT = 46,
	KEY_SLASH = 47,
	KEY_SEMI = 59,
	KEY_APOST = 39,
	KEY_LBRACK = 91,
	KEY_RBRACK = 93,
	KEY_BACKSL = 92
};

typedef enum e_event
{
	ON_DESTROY = 17
}	t_event;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_pointd
{
	double	x;
	double	y;
}	t_pointd;

typedef struct s_pos
{
	t_point	a;
	t_point	b;
}	t_pos;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_gradient
{
	int	color_a;
	int	color_b;
}	t_gradient;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_loc
{
	int			altitude;
	int			color;
	t_point		point;
	t_point		iso;
	t_pointd	iso_t;
}	t_loc;

typedef struct s_map
{
	t_loc	**loc;
	t_pos	*position;
	int		cols;
	int		rows;
	int		width;
	int		height;
}	t_map;

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
	int		diff[4];
}	t_window;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_img		map;
	t_img		menu;
	t_window	*window;
	t_map		*data;
}	t_fdf;

void	put_pixel(t_img *img, int x, int y, int color);
void	fill_background(t_img *img, int color);

void	draw_line(t_img *img, t_point a, t_point b, int color);
void	draw_line_gradient(t_img *img, t_point a, t_point b, t_gradient grad);
void	bres_step(t_point *p, t_point d, t_point s, int *err);
int		step_at_color(int a, int b, int step, int steps);
int		color_at_step(t_gradient g, int step, int steps);

void	draw_map(t_img *img, t_map *map);
void	init_zoom(t_window *window, t_map *map);
void	map_offset(t_window *window);
void	print_menu(t_fdf *env);

t_point	get_map_size(const char *file);
t_loc	**read_map(char *file, t_window *win);

int		render(t_fdf *env);
int		key_hook(int keycode, void *param);
int		close_hook(void *param);
int		close_window(void *param);
void	exit_fdf(t_fdf *env);

#endif
