#include "libft.h"
#include <fcntl.h>
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include "fileft.h"

int main(int ac, char **av)
{
	char *file;
	t_map	*map;

	if (ac > 1)
	{
		file = get_file(av[1]);
		ft_printf("%s", file);
		map = init_map(file);
		ft_printf("\nheight: %d\nwidth: %d\nnew count: %d", map->height, map->width,map->map[3][3]);
	}

	/* t_fdf	*env; */
	/**/
	/* env = (t_fdf*)malloc(sizeof (t_fdf)); */
	/* env->mlx = mlx_init(); */
	/* env->win = mlx_new_window(env->mlx, WIDTH/2, HEIGHT/2, "hello world"); */
	/* env->img = mlx_new_image(env->mlx, WIDTH/2, HEIGHT/2); */
	/* mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0); */
	/* env->data_add = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian); */
	/* for (int i = 0; i < 100; i++) */
	/* { */
	/* 	for (int j = 0; j < 100; j++) */
	/* 	{ */
	/* 		put_pixel(env, i, j, 0xFF0000); // Red color */
	/* 	} */
	/* } */
	/* mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0); */
 /*    mlx_loop(env->mlx); */
	/* ft_free(env); */
 /*    return (0); */
}
