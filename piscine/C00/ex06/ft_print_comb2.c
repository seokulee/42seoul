/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:25:35 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/14 17:25:22 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_itoa(int left, int right, int num_arr[])
{
	num_arr[0] = (left / 10);
	num_arr[1] = (left % 10);
	num_arr[2] = (right / 10);
	num_arr[3] = (right % 10);
}

void	ft_print_bundle(int left, int right)
{
	int	num_arr[4];

	ft_itoa(left, right, num_arr);
	ft_putchar(num_arr[0] + 48);
	ft_putchar(num_arr[1] + 48);
	ft_putchar(' ');
	ft_putchar(num_arr[2] + 48);
	ft_putchar(num_arr[3] + 48);
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	while (left < 99)
	{
		right = left + 1;
		while (right <= 99)
		{
			ft_print_bundle(left, right);
			if (!(left == 98 && right == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			right++;
		}
		left++;
	}
}
