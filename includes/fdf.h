/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:48:27 by jriga             #+#    #+#             */
/*   Updated: 2025/06/01 15:06:13 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_fdf 
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data_add;
}			t_fdf;

typedef struct s_map
{
	int	**map;
	int	width;
	int height;	
}			t_map;

void	map_get_dimensions(t_map *map, const char *file);
t_map	*init_map(const char *file);
void	put_pixel(t_fdf *env, int x, int y, int color);

#endif
