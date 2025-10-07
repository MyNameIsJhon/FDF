/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:50:45 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:28:53 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "fileft.h"
#include <fcntl.h>

void	print_menu(t_fdf *env)
{
	int		y;
	int		fd;
	char	*instructs;
	char	*ch;

	fd = open("./menu_txt/menu.txt", O_RDONLY);
	if (fd < 0)
		return ;
	y = 30;
	fill_background(&env->menu, 0xFFFFFF);
	mlx_put_image_to_window(env->mlx, env->win, env->menu.ptr, 0, 0);
	instructs = get_next_line(fd);
	while (instructs)
	{
		ch = ft_strchr(instructs, '\n');
		*ch = 0;
		mlx_string_put(env->mlx, env->win, 10, y += 20, 0x000000,
			instructs);
		free(instructs);
		instructs = get_next_line(fd);
	}
	close(fd);
}
