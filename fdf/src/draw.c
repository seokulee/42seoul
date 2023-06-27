#include "fdf.h"

void	draw(t_map *map, t_mlx *mlx, t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->ordinate)
	{
		x = 0;
		while (x < map->abscissa)
		{
			if (x < map->abscissa - 1)
				bresenham(x, y, x + 1, y, mlx, map, image);
			if (y < map->ordinate - 1)
				bresenham(x, y, x, y + 1, mlx, map, image);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, image->img_ptr, mlx->win_x_max / 2, mlx->win_y_max / 2);
}
