#include "fdf.h"

void	init_mlx(t_mlx *mlx, t_map *map)
{
	mlx->win_col = 1200;
	mlx->win_row = 800;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		msg_error_no(ERR_MLX, 1);
	mlx->win_ptr = \
	mlx_new_window(mlx->mlx_ptr, mlx->win_col, mlx->win_row, map->name);
}
