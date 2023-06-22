/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/28 19:41:45 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*p;
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	p = (int *)malloc(sizeof(int) * (max - min));
	if (!p)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		p[i] = min + i;
		i++;
	}
	*range = p;
	return (max - min);
}
