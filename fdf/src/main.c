#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;
	t_image	image;

	if (argc != 2)
		msg_error_no(ERR_ARGC, 1);
	init(&map, &mlx, &image, argv);
	print_map(&map);
	return (0);
}