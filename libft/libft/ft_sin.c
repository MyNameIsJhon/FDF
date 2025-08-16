/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:11:57 by jriga             #+#    #+#             */
/*   Updated: 2025/08/12 23:13:39 by jriga            ###   ########.fr       */
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

static double	ft_sin_poly(double x)
{
	double	u;
	double	r;

	u = x * x;
	r = -1.0 / 5040.0;
	r = r * u + 1.0 / 120.0;
	r = r * u - 1.0 / 6.0;
	r = r * u + 1.0;
	return (x * r);
}

double	ft_sin(double x)
{
	double	y;

	y = ft_wrap_pi(x);
	if (y > FT_PI_2)
		return (ft_sin_poly(FT_PI - y));
	if (y < -FT_PI_2)
		return (-ft_sin_poly(FT_PI + y));
	return (ft_sin_poly(y));
}
