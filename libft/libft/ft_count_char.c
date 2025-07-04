/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:50:41 by jriga             #+#    #+#             */
/*   Updated: 2025/06/01 13:08:43 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcount_char(const char *str, char c)
{
    int i;

	i = 0;
    if (!str)
        return 0;
    while (*str)
    {
        if (*str == c)
            i++;
        str++;
    }
    return i;
}
