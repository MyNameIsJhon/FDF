#include "libft.h"
#include "fileft.h"
#include "fdf.h"

char ***read_map(const char *path)
{
	char	*file;
	char	***map;
	int		height;
	char	**splited;
	int		i;

	file = get_file((char *)path);
	splited = ft_split(file, '\n');
	free(file);
	height = ft_strslen((const char**)splited);
	map = malloc(sizeof(char ***) * (height + 1));	
	if (!map)
	{
		freestrs(splited, height + 1);
		return (NULL);
	}
	i = 0;
	while (splited[i])
	{
		map[i] = ft_split(splited[i], ' ');
		i++;
	}
	freestrs(splited, height + 1);
	map[i] = NULL;
	return (map);
}

t_loc	**init_loc(t_map *map, char ***c_map)
{
	t_loc **locs;
	int		i;
	int		j;
	char	*chr;

	locs = malloc(sizeof(t_loc *) * (map->rows + 1));
	if (!locs)
		return (NULL);
	i = 0;
	while (c_map[i])
	{
		locs[i] = malloc(sizeof(t_loc) * (ft_strslen((const char **)c_map[i]) + 1));
		j = 0;
		while (c_map[i][j])
		{
			locs[i][j].altitude = ft_atoi(c_map[i][j]);
			chr = ft_strchr(c_map[i][j], ',');
			if (chr)
				locs[i][j].color = ft_atoi_hex(chr + 1);
			else
				locs[i][j].color = 0xFFFFFF;
			locs[i][j].point.x = j - ((map->cols - 1) / 2);
			locs[i][j].point.y = i - ((map->rows - 1) / 2);

			j++;
		}
		i++;
	}
	return (locs);
}

t_map *init_map(const char *path, t_window *window)
{
    t_map *map = malloc(sizeof(*map));
    if (!map) return NULL;

    char ***c_map = read_map(path);
    map->rows = ft_strsslen((const char ***)c_map);
    map->cols = ft_strslen((const char **)c_map[0]);
	window->var_alt = 1;

    map_initzoom(window, map);
    map_offset(window, map);

    map->loc = init_loc(map, c_map);
    ft_printf("the map has %d rows and %d cols\n", map->rows, map->cols);
    return map;
}

