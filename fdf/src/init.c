#include "fdf.h"

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
