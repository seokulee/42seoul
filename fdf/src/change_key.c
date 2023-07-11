/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:13 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:14 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_offset(int key, t_fdf *fdf)
{
	if (key == LEFT_AR)
		fdf->camera->x_offset += 20;
	else if (key == RIGHT_AR)
		fdf->camera->x_offset -= 20;
	else if (key == DW_AR)
		fdf->camera->y_offset -= 20;
	else if (key == UP_AR)
		fdf->camera->y_offset += 20;
}

void	change_altitude(int key, t_fdf *fdf)
{
	if (key == PLUS)
		fdf->camera->z_zoom++;
	else if (key == MINUS)
	{
		if (fdf->camera->z_zoom > 1)
			fdf->camera->z_zoom--;
	}
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == KEY_I)
		fdf->camera->projection = ISOMETRIC;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
}

void	change_angle_key(int key, t_fdf *fdf)
{
	if (key == KEY_Z)
		fdf->camera->gamma += 0.1;
	else if (key == KEY_A)
		fdf->camera->gamma -= 0.1;
	else if (key == KEY_X)
		fdf->camera->alpha += 0.1;
	else if (key == KEY_S)
		fdf->camera->alpha -= 0.1;
	else if (key == KEY_C)
		fdf->camera->beta += 0.1;
	else if (key == KEY_D)
		fdf->camera->beta -= 0.1;
}
