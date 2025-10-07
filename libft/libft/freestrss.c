/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestrss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:39:45 by jriga             #+#    #+#             */
/*   Updated: 2025/09/04 16:40:59 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	freestrss(char ****strss)
{
	int	i;

	if (!strss || !*strss)
		return ;
	i = 0;
	while ((*strss)[i])
	{
		freestrs((*strss)[i], ft_strslen((const char **)(*strss)[i]) + 1);
		i++;
	}
	free(*strss);
	*strss = NULL;
}
