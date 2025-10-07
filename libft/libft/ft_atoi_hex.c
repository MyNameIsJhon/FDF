/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:30:46 by jriga             #+#    #+#             */
/*   Updated: 2025/08/14 20:31:10 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_ishex(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}

static int	ft_hexval(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	return (10 + c - 'A');
}

long	ft_atoi_hex(const char *s)
{
	long	sign;
	long	n;

	if (!s)
		return (0);
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\v' || *s == '\f' || *s == '\r')
		s++;
	sign = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		s += 2;
	n = 0;
	while (ft_ishex(*s))
	{
		n = (n << 4) + ft_hexval(*s);
		s++;
	}
	return (n * sign);
}
