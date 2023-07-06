#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;
	t_map	map;

	if (argc != 2)
		terminate(ERR_ARGC, 1);
	ft_memset(&map, 0, sizeof(t_map));
	read_map(&map, argv);
	fdf = init_fdf(&map);
	draw(fdf);
	mlx_loop(fdf->mlx);
	//free(fdf);
	return (0);
}
