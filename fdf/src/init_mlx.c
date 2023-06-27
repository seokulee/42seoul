#include "fdf.h"

void	get_gap(t_mlx *mlx, t_map *map);

void	init_mlx(t_mlx *mlx, t_map *map)
{
	mlx->win_x_max = 1200;
	mlx->win_y_max = 800;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		msg_error_no(ERR_MLX, 1);
	mlx->win_ptr = \
	mlx_new_window(mlx->mlx_ptr, mlx->win_x_max, mlx->win_y_max, map->name);
	get_gap(mlx, map);
}

void	get_gap(t_mlx *mlx, t_map *map)
{
	mlx->gap = 20;

	while (map->abscissa * mlx->gap > mlx->win_x_max \
	|| map->ordinate * mlx->gap > mlx->win_y_max)
	{
		mlx->gap--;
	}
}