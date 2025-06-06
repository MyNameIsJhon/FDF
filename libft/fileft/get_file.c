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
#include "vector.h"
#define FILE_BUFF 4096

char *get_file(char *path)
{
	char		buff[FILE_BUFF + 1]; // +1 pour le '\0'
	int			fd;
	ssize_t		bytes;
	char		*file;
	t_vector	*vec;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);

	vec = vector_init(sizeof(char), FILE_BUFF);
	if (!vec)
	{
		close(fd);
		return (NULL);
	}

	while ((bytes = read(fd, buff, FILE_BUFF)) > 0)
	{
		buff[bytes] = '\0'; // null-terminaison pour ft_strlen
		vec = vec_strappend(vec, buff);
		if (!vec)
		{
			close(fd);
			return (NULL);
		}
	}
	if (bytes < 0)
	{
		vec_free(vec);
		close(fd);
		return (NULL);
	}

	file = ft_strdup((char *)vec->content);
	vec_free(vec);
	close(fd);
	return (file);
}
