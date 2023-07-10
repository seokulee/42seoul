#include "fdf.h"

static void	isometric(t_spot *s);

t_spot	*transform_coordinates(t_spot *s, t_fdf *fdf)
{
	s->x *= fdf->map->zoom;
	s->y *= fdf->map->zoom;
	s->z *= fdf->map->zoom / fdf->map->z_dividor;
	isometric(s);
	s->x += fdf->map->x_offset;
	s->y += fdf->map->y_offset;
	return (s);
}

t_spot	*new_spot(int x, int y, t_fdf *fdf)
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

static void	isometric(t_spot *s)
{
	int	prev_x;
	int	prev_y;

	prev_x = s->x;
	prev_y = s->y;
	s->x = (prev_x - prev_y) * cos(0.523599);
	s->y = (prev_x + prev_y) * sin(0.523599) - s->z;
}

void	change_zoom(int key, t_fdf *fdf)
{
	if (key == 24)
		fdf->map->zoom++;
	else if (key == 27)
		fdf->map->zoom--;
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = NULL;
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	if (!fdf->img)
		terminate(ERR_IMG, 1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sl, &fdf->e);
	if (!fdf->addr)
		terminate(ERR_ADDR, 1);
	draw(fdf);
}
