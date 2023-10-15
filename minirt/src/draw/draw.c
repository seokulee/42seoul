#include "minirt.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw(t_data *data, t_scene *scene)
{
	(void)scene;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			my_mlx_pixel_put(data->mlx_img, i, j, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img->img, 0, 0);
	mlx_loop(data->mlx);
}
