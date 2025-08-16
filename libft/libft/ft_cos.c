/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:08:49 by jriga             #+#    #+#             */
/*   Updated: 2025/08/12 23:11:29 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_wrap_pi(double x)
{
	while (x > FT_PI)
		x -= FT_PI2;
	while (x < -FT_PI)
		x += FT_PI2;
	return (x);
}

static double	ft_cos_poly(double x)
{
	double	u;
	double	r;

	u = x * x;
	r = -1.0 / 720.0;
	r = r * u + 1.0 / 24.0;
	r = r * u - 1.0 / 2.0;
	r = r * u + 1.0;
	return (r);
}

double	ft_cos(double x)
{
	double	y;

	y = ft_wrap_pi(x);
	if (y > FT_PI_2)
		return (-ft_cos_poly(FT_PI - y));
	if (y < -FT_PI_2)
		return (-ft_cos_poly(FT_PI + y));
	return (ft_cos_poly(y));
}
