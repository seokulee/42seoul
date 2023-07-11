/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:39 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:41 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_spot *s);

t_spot	*transform_coordinates(t_spot *s, t_fdf *fdf)
{
	s->x *= fdf->camera->zoom;
	s->y *= fdf->camera->zoom;
	s->z *= fdf->camera->z_zoom;
	rotate_x(&s->y, &s->z, fdf->camera->alpha);
	rotate_y(&s->z, &s->x, fdf->camera->beta);
	rotate_z(&s->x, &s->y, fdf->camera->gamma);
	if (fdf->camera->projection == ISOMETRIC)
		isometric(s);
	else if (fdf->camera->projection == PARALLEL)
	{
		fdf->camera->alpha = 0;
		fdf->camera->beta = 0;
		fdf->camera->gamma = 0;
	}
	s->x += fdf->camera->x_offset;
	s->y += fdf->camera->y_offset;
	return (s);
}

static void	isometric(t_spot *s)
{
	rotate_z(&s->x, &s->y, PI / 4);
	rotate_x(&s->y, &s->z, 35.264 / 180.0 * PI);
}
