/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:19:20 by jriga             #+#    #+#             */
/*   Updated: 2025/04/01 15:44:27 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n' || \
			*str == '\r' || *str == '\f'))
		str++;
	if (*str == '-')
	{
		sign = (-1);
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0') * sign;
		str++;
	}
	return (result);
}
