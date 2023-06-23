/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:42:06 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 21:10:35 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	get_info(t_info info, char *s)
{
	*info.row = (s[0] - '0');
	*info.empty = s[1];
	*info.obstacle = s[2];
	*info.occupied = s[3];
}