#include "fdf.h"

int	in_key(int key, t_map *map, t_mlx *mlx, t_image *image)
{
	if (key == 53)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_image(mlx->mlx_ptr, image->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	}
	//else
		//draw(map, mlx, image);
	(void) map;
	return (0);
}
