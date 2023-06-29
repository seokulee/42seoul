#include "fdf.h"

void	init(t_map *map, t_mlx *mlx, char *argv[])
{
	init_map(map, argv);
	parse_map(map);
	init_mlx(mlx, map);
}
