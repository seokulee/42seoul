#include "minirt.h"

t_scene	*init_scene(void)
{
	t_scene	*new_scene;

	new_scene = (t_scene *)malloc(sizeof(t_scene));
	if (new_scene == NULL)
		return (NULL);
	new_scene->ambient = NULL;
	new_scene->camera = NULL;
	new_scene->lights = NULL;
	new_scene->objects = NULL;
	new_scene->cnt_ambient = 0;
	new_scene->cnt_cameras = 0;
	new_scene->cnt_lights = 0;
	new_scene->cnt_objects = 0;
	return (new_scene);
}

t_data	*init_data(void)
{
	t_data	*new_data;
	int		width;
	int		height;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (new_data == NULL)
		return (NULL);
	new_data->mlx = mlx_init();
	mlx_get_screen_size(new_data->mlx, &width, &height);
	new_data->mlx_win = mlx_new_window(new_data->mlx, width, height, "miniRT");
	new_data->mlx_img = (t_img *)malloc(sizeof(t_img));
	if (new_data->mlx_img == NULL)
		return (NULL);
	new_data->mlx_img->img = mlx_new_image(new_data->mlx, width, height);
	new_data->mlx_img->addr = mlx_get_data_addr(new_data->mlx_img->img,
			&new_data->mlx_img->bits_per_pixel,
			&new_data->mlx_img->line_length,
			&new_data->mlx_img->endian);
	return (new_data);
}
