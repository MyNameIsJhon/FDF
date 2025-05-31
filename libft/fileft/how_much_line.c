/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_much_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:30:27 by jriga             #+#    #+#             */
/*   Updated: 2025/05/31 18:46:06 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fileft.h"
#include <stdlib.h>
#include <stdio.h>

int	how_much_line(char *filepath)
{
	int		fd;
	int	i;
	char	*line;

	fd = open(filepath, O_RDONLY);
	i = 0;
	if (fd <= 0)
		return 0;
	while ((line = get_next_line(fd)))
	{
		printf("%i",i++);
		free(line);
	}
	close(fd);
	return (i);
}
