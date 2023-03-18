/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:26:04 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 21:10:39 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	strlen(char *s);

int	is_valid(char **str)
{
	t_info	info;
	int		col;
	int		i;

	if (strlen(str[0]) != 4 || !check_info(str[0]))
		return (0);
	else
		get_info(&info, str[0]);
	i = 1;
	col = strlen(str[i]);
	if (col == 0)
		return (0);
	while (str[i])
	{
		if (stranger(str[i], t_info) || strlen(str[i]) != col)
			return (0);
		if (str[i][col - 1] != '\n')
			return (0);
		i++;
	}
	if (i - 1 != info.row)
		return (0);
	return (1);
}
