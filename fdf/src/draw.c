#include "fdf.h"

void	draw_line(t_spot *s, t_spot *f, t_fdf *fdf);
void	draw_pixel(t_fdf *fdf, int x, int y, int clr);
void	isometric(t_spot *s, t_map *map);

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while(y < fdf->map->y_size)
	{
		x = 0;
		while(x < fdf->map->x_size)
		{
			if (x < fdf->map->x_size - 1)
				draw_line(new_spot(x, y, fdf), new_spot(x + 1, y, fdf), fdf);
			if (y < fdf->map->y_size - 1)
				draw_line(new_spot(x, y, fdf), new_spot(x, y + 1, fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	draw_line(t_spot *s, t_spot *f, t_fdf *fdf)
{
	t_spot	cur;
	t_spot	step;
	t_spot	diff;
	int		det;

	s->x *= 20;
	s->y *= 20;
	f->x *= 20;
	f->y *= 20;
	isometric(s, fdf->map);
	isometric(f, fdf->map);
	s->x += 100;
	s->y += 100;
	f->x += 100;
	f->y += 100;
	init_bresenham(s, f, &step, &diff);
	cur = *s;
	if (diff.x > diff.y)
	{
		det = (2 * diff.y) - diff.x;
		while (cur.x != f->x)
		{
			draw_pixel(fdf, cur.x, cur.y, get_color(s, f, cur));
			cur.x += step.x;
			if (det < 0)
				det += 2 * diff.y;
			else
			{
				cur.y += step.y;
				det += 2 * (diff.y - diff.x);
			}
		}
	}
	else
	{
		det = (2 * diff.x) - diff.y;
		while (cur.y != f->y)
		{
			draw_pixel(fdf, cur.x, cur.y, get_color(s, f, cur));
			cur.y += step.y;
			if (det < 0)
				det += 2 * diff.x;
			else
			{
				cur.x += step.x;
				det += 2 * (diff.x - diff.y);
			}
		}
	}
	free(s);
	s = NULL;
	free(f);
	f = NULL;
}

void	draw_pixel(t_fdf *fdf, int x, int y, int clr)
{
	int	i;
	int c;

	c = 0;
	if ((0 <= x && x < fdf->win_width) && (0 <= y && y < fdf->win_height))
	{
		i = (x * fdf->bpp / 8) + (y * fdf->sl);
		fdf->addr[i] = clr;
		fdf->addr[++i] = clr >> 8;
		fdf->addr[++i] = clr >> 16;
		c++;
	}
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

void	isometric(t_spot *s, t_map *map)
{
	int	prev_x;
	int	prev_y;
	int	z;

	prev_x = s->x;
	prev_y = s->y;
	z = map->z_arr[(prev_y / 20) * map->x_size + (prev_x / 20)] * 10;
	s->x = (prev_x - prev_y) * cos(0.46364671579);
	s->y = (prev_x + prev_y) * sin(0.46364671579) - z;
}
