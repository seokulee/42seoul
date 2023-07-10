#include "fdf.h"

static void	init_camera(t_fdf *fdf);

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf) * 1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		terminate(ERR_MLX, 1);
	mlx_get_screen_size(fdf->mlx, &fdf->win_width, &fdf->win_height);
	fdf->win = mlx_new_window \
	(fdf->mlx, fdf->win_width, fdf->win_height, map->name);
	if (!fdf->win)
		terminate(ERR_WIN, 1);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	if (!fdf->img)
		terminate(ERR_IMG, 1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sl, &fdf->e);
	if (!fdf->addr)
		terminate(ERR_ADDR, 1);
	fdf->map = map;
	init_camera(fdf);
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse) * 1);
	if (!fdf->mouse)
		terminate(ERR_MEM, 1);
	return (fdf);
}

t_spot	*init_spot(int x, int y, t_fdf *fdf)
{
	t_spot	*spot;

	spot = (t_spot *)malloc(sizeof(t_spot) * 1);
	spot->x = x;
	spot->y = y;
	spot->z = fdf->map->z_arr[y * fdf->map->x_size + x];
	if (fdf->map->clr_arr[y * fdf->map->x_size + x] != -1)
		spot->clr = fdf->map->clr_arr[y * fdf->map->x_size + x];
	else
		spot->clr = DEFAULT_CLR;
	return (spot);
}

void	init_bresenham(t_spot *s, t_spot *f, t_spot *step, t_spot *diff)
{
	diff->x = f->x - s->x;
	diff->y = f->y - s->y;
	if (diff->x < 0)
	{
		step->x = -1;
		diff->x *= -1;
	}
	else
		step->x = 1;
	if (diff->y < 0)
	{
		step->y = -1;
		diff->y *= -1;
	}
	else
		step->y = 1;
}

static void	init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera) * 1);
	if (!camera)
		terminate(ERR_MEM, 1);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->zoom = 200;
	camera->x_offset = (fdf->win_width / 2) - fdf->map->x_size;
	camera->y_offset = (fdf->win_height / 2) - fdf->map->y_size;
	while (fdf->map->x_size * camera->zoom + camera->x_offset > fdf->win_width)
		camera->zoom -= 5;
	camera->zoom /= 2;
	camera->z_zoom = 1;
	camera->projection = ISOMETRIC;
	fdf->camera = camera;
}
