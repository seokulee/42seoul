/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stranger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:20:59 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 21:10:13 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	stranger(char *s, t_info info)
{
	char	info[4];
	int		i;
	int		j;

	info[0] = info.empty;
	info[1] = info.obstacle;
	info[2] = info.occupied;
	info[3] = '\0';
	i = 0;
	while (s[i])
	{
		j = 0;
		while (info[j])
		{
			if (s[i] == info[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
