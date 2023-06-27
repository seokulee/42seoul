#include "fdf.h"

void	init_image(t_image *image, t_mlx *mlx)
{
	image->bits_per_pixel = 0;
	image->size_line = 0;
	image->endian = 0;
	image->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x_max / 2, mlx->win_y_max / 2);
	image->pos = mlx_get_data_addr(image->img_ptr, \
	&image->bits_per_pixel, &image->size_line, &image->endian);
}
