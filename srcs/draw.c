/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:22:25 by jriga             #+#    #+#             */
/*   Updated: 2025/05/31 16:43:00 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void put_pixel(t_fdf *env, int x, int y, int color)
{
	int offset;

	offset = y * env->size_line + x * (env->bpp / 8);
	if (env->endian == 0)
	{
		env->data_add[offset + 0] = color & 0xFF;
		env->data_add[offset + 1] = (color >> 8) & 0xFF;
		env->data_add[offset + 2] = (color >> 16) & 0xFF;
		env->data_add[offset + 3] = 0;
	}
	else 
	{
		env->data_add[offset] = (color >> 24) & 0xFF;
		env->data_add[offset] = (color >> 16) & 0xFF;
		env->data_add[offset] = (color >> 8) & 0xFF;
		env->data_add[offset] = color & 0xFF;
	}
}
