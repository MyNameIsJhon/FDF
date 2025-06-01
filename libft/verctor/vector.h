/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:03:52 by jriga             #+#    #+#             */
/*   Updated: 2025/06/01 17:35:17 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
#include <stddef.h>

typedef enum vec_type
{
	INT,
	LONG,
	CHAR,
} vec_type;

typedef struct s_vector
{
	void		*content;
	size_t		max;
	size_t		actual;
	int			size_type;
	vec_type	type;
}			t_vector;

# endif
