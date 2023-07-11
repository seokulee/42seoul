/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:19 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:20 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_spot *s, t_spot *f, t_fdf *fdf);
static void	draw_pixel(t_fdf *fdf, int x, int y, int clr);
static void	free_spot(t_spot *s, t_spot *f);

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->y_size)
	{
		x = 0;
		while (x < fdf->map->x_size)
		{
			if (x < fdf->map->x_size - 1)
				draw_line(transform_coordinates(init_spot(x, y, fdf), fdf), \
				transform_coordinates(init_spot(x + 1, y, fdf), fdf), fdf);
			if (y < fdf->map->y_size - 1)
				draw_line(transform_coordinates(init_spot(x, y, fdf), fdf), \
				transform_coordinates(init_spot(x, y + 1, fdf), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

/* dirty code of det 
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
	*/

static void	draw_line(t_spot *s, t_spot *f, t_fdf *fdf)
{
	t_spot	cur;
	t_spot	step;
	t_spot	diff;
	int		det[2];

	init_bresenham(s, f, &step, &diff);
	cur = *s;
	det[0] = diff.x - diff.y;
	while (cur.x != f->x || cur.y != f->y)
	{
		draw_pixel(fdf, cur.x, cur.y, get_color(s, f, cur));
		det[1] = det[0] * 2;
		if (det[1] < diff.x)
		{
			det[0] += diff.x;
			cur.y += step.y;
		}
		if (det[1] > -diff.y)
		{
			det[0] -= diff.y;
			cur.x += step.x;
		}
	}
	free_spot(s, f);
}

static void	draw_pixel(t_fdf *fdf, int x, int y, int clr)
{
	int	i;

	if ((0 <= x && x < fdf->win_width) && (0 <= y && y < fdf->win_height))
	{
		i = (x * fdf->bpp / 8) + (y * fdf->sl);
		fdf->addr[i] = clr;
		fdf->addr[++i] = clr >> 8;
		fdf->addr[++i] = clr >> 16;
	}
}

static void	free_spot(t_spot *s, t_spot *f)
{
	free(s);
	s = NULL;
	free(f);
	f = NULL;
}
