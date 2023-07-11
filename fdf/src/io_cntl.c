/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_cntl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:29 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:30 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_pressed(int key, void *param);
static int	mouse_pressed(int mouse, int x, int y, void *param);
static int	mouse_moved(int x, int y, void *param);
static int	mouse_released(int mouse, int x, int y, void *param);

void	io_cntl(t_fdf *fdf)
{
	mlx_hook(fdf->win, 6, 0, mouse_moved, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_pressed, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_released, fdf);
	mlx_hook(fdf->win, 2, 0, key_pressed, fdf);
}

static int	key_pressed(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == ESCAPE)
		free_all(param);
	else if (key >= LEFT_AR && key <= UP_AR)
		change_offset(key, fdf);
	else if (key == PLUS || key == MINUS)
		change_altitude(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if ((key >= KEY_A && key <= KEY_D) || (key >= KEY_Z && key <= KEY_C))
		change_angle_key(key, fdf);
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = NULL;
	fdf->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	if (!fdf->img)
		terminate(ERR_IMG, 1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sl, &fdf->e);
	if (!fdf->addr)
		terminate(ERR_ADDR, 1);
	draw(fdf);
	return (0);
}

static int	mouse_pressed(int mouse, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void) x;
	(void) y;
	fdf = (t_fdf *)param;
	if (mouse == WHEEL_UP || mouse == WHEEL_DW)
		change_zoom(mouse, fdf);
	else if (mouse == LEFT_BT)
		fdf->mouse->mb1_pressed = 1;
	else if (mouse == RIGHT_BT)
		fdf->mouse->mb2_pressed = 1;
	else if (mouse == WHEEL_BT)
		fdf->mouse->wheel_pressed = 1;
	return (0);
}

static int	mouse_released(int mouse, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (mouse == LEFT_BT)
		fdf->mouse->mb1_pressed = 0;
	else if (mouse == RIGHT_BT)
		fdf->mouse->mb2_pressed = 0;
	else if (mouse == WHEEL_BT)
		fdf->mouse->wheel_pressed = 0;
	return (0);
}

static int	mouse_moved(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->prev_x = fdf->mouse->cur_x;
	fdf->mouse->prev_y = fdf->mouse->cur_y;
	fdf->mouse->cur_x = x;
	fdf->mouse->cur_y = y;
	change_angle_mouse(x, y, fdf);
	return (0);
}
