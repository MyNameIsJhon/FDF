/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:20:27 by jriga             #+#    #+#             */
/*   Updated: 2025/06/01 17:32:28 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

#define VECTOR_MAX 1024
#define VECTOR_CAP 4020

t_vector *vector_init(int type)
{
	t_vector *vec;

	vec = ft_malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	vec->content = ft_malloc(VECTOR_CAP);
	vec->actual = 0;
	vec->max = VECTOR_CAP;
	return (vec);
}
