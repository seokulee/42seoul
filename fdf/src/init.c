#include "fdf.h"

void	init_map(t_fdf *fdf);
static void	get_center(t_spot *s);

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf) * 1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		terminate(ERR_MLX, 1);
	mlx_get_screen_size(fdf->mlx, &fdf->win_width, &fdf->win_height);
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, map->name);
	if (!fdf->win)
		terminate(ERR_WIN, 1);
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	if (!fdf->img)
		terminate(ERR_IMG, 1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sl, &fdf->e);
	if (!fdf->addr)
		terminate(ERR_ADDR, 1);
	fdf->map = map;
	init_map(fdf);
	return (fdf);
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

void	init_map(t_fdf *fdf)
{
	t_spot	center;

	center.x = fdf->map->x_size;
	center.x = fdf->map->y_size;
	get_center(&center);
	fdf->map->x_offset = (fdf->map->x_size / 2) - center.x;
	fdf->map->y_offset = (fdf->map->y_size / 2) - center.y;
	while (fdf->map->zoom * center.x * 2 > fdf->win_width)
		fdf->map->zoom -= 5;
	fdf->map->zoom = fdf->map->zoom / 2;
	//while (fdf->map->zoom / fdf->map->z_dividor * center.y * 2 - fdf->map->z_max < 0)
	//	fdf->map->z_dividor++;
	//fdf->map->z_dividor /= 2;
}

static void	get_center(t_spot *s)
{
	int	prev_x;
	int	prev_y;

	prev_x = s->x;
	prev_y = s->y;
	s->x = (prev_x - prev_y) * cos(0.523599) / 2;
	s->y = (prev_x + prev_y) * sin(0.523599) / 2;
}
