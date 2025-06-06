/* ************************************************************************** */
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
#include <stdlib.h>

#define VEC_MULTIPLIER 2


t_vector *vector_init(int size_type, size_t space)
{
	t_vector *vec;

	vec = ft_malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	vec->content = ft_malloc(size_type * space);
	if (!vec->content)
	{
		ft_free(vec);
		return (NULL);
	}
	vec->actual = 0;
	vec->max = space;
	vec->size_type = size_type;

	if (size_type == sizeof(char))
		((char *)vec->content)[0] = '\0';
	return (vec);
}

static t_vector *vec_realloc(t_vector *vec)
{
	void *new = ft_realloc(vec->content, vec->max * VEC_MULTIPLIER);
	if (!new)
		return (NULL);
	vec->content = new;
	vec->max *= VEC_MULTIPLIER;
	return (vec);
}

t_vector *vec_strappend(t_vector *vec, char *data)
{
	size_t	len;

	if (!vec || !data)
		return (vec);
	len = ft_strlen(data);
	while (vec->actual + len >= vec->max)
	{
		vec = vec_realloc(vec);
		if (!vec)
			return (NULL);
	}
	ft_memcpy((char *)vec->content + vec->actual, data, len);
	vec->actual += len;
	((char *)vec->content)[vec->actual] = '\0';
	return (vec);
}

void vec_free(t_vector *vec)
{
	if (!vec)
		return ;
	if (vec->content)
		ft_free(vec->content);
	ft_free(vec);
}
