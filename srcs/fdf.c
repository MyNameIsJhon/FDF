#include "libft.h"
#include <fcntl.h>
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int main(void)
{
	t_fdf	*env;
	
	env = (t_fdf*)ft_malloc(sizeof (t_fdf));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "hello world");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->data_add = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian)
    mlx_loop(env->mlx);
	ft_free(env);

    return (0);
}
