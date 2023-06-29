#include "fdf.h"

void	bresenham(float x, float y, float x1, float y1, t_map *map, t_mlx *mlx);
void	isometric(float *x, float *y, int z);

int	print_key(int key, t_mlx *mlx)
{
	printf("%d\n", key);

	if (key == 53)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	}
	return (0);
}

void	draw(t_map *map, t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			bresenham(x, y, x + 1, y, map, mlx);
			bresenham(x, y, x, y + 1, map, mlx);
			x++;
		}
		y++;
	}
}

int max1(int a, int b)
{
	return (a > b) ? a : b;
}

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_map *map, t_mlx *mlx)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;
	//(void) map;
	z = map->z[(int)y][(int)x];
	z1 = map->z[(int)y1][(int)x1];
	x *= 20;
	x1 *= 20;
	y *= 20;
	y1 *= 20;
	x_step = x1 - x;
	y_step = y1 - y;
	//int color = (map->color[(int)y/20][(int)x/20]) ? (map->color[(int)y/20][(int)x/20]) : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	max = max1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}

}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		msg_error_no(ERR_ARGC, 1);
	init(&map, &mlx, argv);
	print_map(&map);
	draw(&map, &mlx);
	mlx_key_hook(mlx.win_ptr, print_key, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}