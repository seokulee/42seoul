#include "minirt.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
#include <stdio.h>
void	draw(t_data *data, t_scene *scene)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	/* trace every pixel [-1.0, 1.0] */
	while (y < data->height)
	{
		while (x < data->width)
		{
			trace_ray(data, scene, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	/* trace ray and every objs per pixcel */
	/* put pixcel to image */
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img->img, 0, 0);
}
