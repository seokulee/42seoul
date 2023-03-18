/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:06:28 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/30 22:09:26 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*results;
	int	i;

	results = (int *)malloc(sizeof(int) * length);
	if (!results)
		return (0);
	i = 0;
	while (i < length)
	{
		results[i] = (*f)(tab[i]);
		i++;
	}
	return (results);
}	
