/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:15 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:16 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_zoom(int mouse, t_fdf *fdf)
{
	if (mouse == WHEEL_UP)
		fdf->camera->zoom++;
	else if (mouse == WHEEL_DW)
		fdf->camera->zoom--;
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

void	change_angle_mouse(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse->mb1_pressed == 1 && fdf->mouse->mb2_pressed == 1)
	{
		fdf->camera->x_offset += (x - fdf->mouse->prev_x);
		fdf->camera->y_offset += (y - fdf->mouse->prev_y);
	}
	else if (fdf->mouse->mb2_pressed == 1)
	{
		fdf->camera->beta += (x - fdf->mouse->prev_x) * 0.002;
		fdf->camera->alpha -= (y - fdf->mouse->prev_y) * 0.002;
	}
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
