#include "libft.h"
#include "fileft.h"
#include "fdf.h"


int	map_get_width(const char *file)
{
	int	width;
	int	len;

	width = 0;
	len = 0;
	while (*file)
	{
		if (ft_isdigit(*file))
		{
			while (ft_isdigit(*file))
				file++;
			len++;
		}
		if (*file == '\n')
		{
			if (len > width)
				width = len;
			len = 0;
		}
		file++;
	}
	return width;
}

void	map_get_dimensions(t_map *map, const char *file)
{
	if (!map || !file)
		return ;
	map->height = ft_strcount_char(file, '\n');
	map->width = map_get_width(file);
	if (map->width > 0)
		map->height++;
}

t_bool	map_alloc(t_map *map)
{
	int i;

	if (!map && !map->height && !map->width)
		return (0);
	map->map = (int **)ft_malloc(sizeof(int *) * (map->height + 1));
	if (!map->map)
		return (0);
	i = 0;
	while (i <= map->height)
	{
		map->map[i] = ft_malloc(sizeof(int) * map->width + 1);
		if (!map->map[i])
			return (0);
		i++;
	}
	return (1);
}

void	map_parser(t_map *map, const char *file)
{
	int	x;
	int	y;

	if (!map || !file)	
		return ;
	x = 0;
	y = 0;
	while (*file && map->height > y)
	{
		if (ft_isdigit(*file))
		{
			map->map[y][x] = ft_atoi(file);
			while (ft_isdigit(*file))
				file++;
			x++;
		}
		if (*file == '\n')
		{
			y++;
			x = 0;
		}
		file++;
	}
}

t_map *init_map(const char *file)
{
	t_map	*map;

	if (!file)
		return (NULL);
	map = (t_map *)ft_malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map_get_dimensions(map, file);
	map_alloc(map);
	map_parser(map, file);
	return map;
}
