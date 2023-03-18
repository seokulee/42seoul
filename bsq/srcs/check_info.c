/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:13:56 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 21:10:29 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_info(char *s)
{
	int		i;
	int		j;
	char	*dup;

	dup = s;
	i = 0;
	while (s[i])
	{
		if (s[i] < ' ' || s[i] > 127)
			return (0);
		j = 0;
		while (i > j)
		{
			if (s[i] == dup[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
