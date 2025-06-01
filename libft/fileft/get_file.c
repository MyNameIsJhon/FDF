/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriga <jriga@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:07:19 by jriga             #+#    #+#             */
/*   Updated: 2025/06/01 17:02:14 by jriga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fileft.h"
#include "libft.h"
#include "stdlib.h"
# define FILE_BUFF 4096
//TODO: finir fonction 
typedef struct s_content
{
	char	*content;
	size_t	max;
	size_t	actual;
}			t_content;

static ssize_t read_buf(char *buffer, int fd)
{
	ssize_t bytes;

	bytes = read(fd, buffer, FILE_BUFF);
	return (bytes);
}

char *get_file(char *path)
{
	char		buff[BUFFER_SIZE];
	int			fd;
	ssize_t		bytes;
	t_content	file;

	fd = open(path, O_RDONLY);
	bytes = 1;
	if (fd < 0)
		return (NULL);
	while (bytes > 0)
	{

	}
}
