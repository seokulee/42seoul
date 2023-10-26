#include "minirt.h"

void	trace_ray(t_data *data, t_scene *scene, int x, int y)
{
	t_ray	ray;
	t_rgb	color;

	ray = get_ray(data, scene, x, y);
	color = ray_color(ray, scene);
	my_mlx_pixel_put(data->mlx_img, x, y, color);
}
