#include "fdf.h"

void	terminate(char *msg, int exit_num)
{
	write(2, msg, ft_strlen(msg));
	exit(exit_num);
}

void	free_all(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->map->z_arr);
	free(fdf->map->clr_arr);
	free(fdf->camera);
	free(fdf->mouse);
	free(fdf);
	exit(0);
}

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
	io_cntl(fdf);
	mlx_loop(fdf->mlx);
	free_all(fdf);
	return (0);
}
