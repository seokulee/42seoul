/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:19:35 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/15 16:16:27 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	arr[3];
	char	comma_blank[2];

	arr[0] = '0';
	comma_blank[0] = ',';
	comma_blank[1] = ' ';
	while (arr[0] <= '9')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '9')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				write(1, arr, 3);
				if (arr[0] == '7')
					break ;
				write(1, comma_blank, 2);
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}
