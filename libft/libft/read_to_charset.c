/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:21:59 by jriga             #+#    #+#             */
/*   Updated: 2025/10/05 15:22:58 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*read_to_charset(char *str, char *buff, char *charset)
{
	int	i;

	if (!str || !buff)
		return (NULL);
	i = 0;
	while (str[i] && !ft_ischarset(str[i], charset))
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	while (ft_ischarset(str[i], charset))
		i++;
	return (str + i);
}
