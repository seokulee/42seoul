/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:02:15 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/15 16:27:45 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_make_arr(int n, int arr[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
}

void	ft_print_pack(int n, int arr[])
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 1;
	while (i < (n - 1))
	{
		if (arr[i] >= arr[i + 1])
			boolean = 0;
		i++;
	}
	i = 0;
	while (boolean && i < n)
	{
		ft_putchar(arr[i] + '0');
		if (arr[0] < (10 - n) && i == (n - 1))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[10];

	if (n > 10 || n < 0)
		return ;
	i = 0;
	ft_make_arr(n, arr);
	while (arr[0] <= (10 - n))
	{
		ft_print_pack(n, arr);
		i = n - 1;
		arr[i]++;
		while (i > 0)
		{
			if (arr[i] > 9)
			{
				arr[i - 1]++;
				arr[i] = 0;
			}
			i--;
		}
	}
}
