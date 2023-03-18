/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:49:14 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/25 12:48:46 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct	s_checkls
{
	int	c[10];
	int	s[19];
	int	bs[19];
};

void	ft_print_path(int *path, int *count)
{
	int		i;
	char	c;

	i = 0;
	*count += 1;
	while (i < 10)
	{
		c = path[i++] + '0';
		write(1, &c, 1);
	}
	write(1, &"\n", 1);
}

void	ft_make_arr(int arr[], int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		arr[i] = 0;
		i++;
	}
}

void	ft_make_path(struct s_checkls checkls, int path[], int row, int *count)
{
	int	col;

	if (row == 10)
		ft_print_path(path, count);
	else
	{
		col = 0;
		while (col < 10)
		{
			if (!(checkls.c[col] || checkls.s[row + col]
					|| checkls.bs[row - col + 9]))
			{
				path[row] = col;
				checkls.c[col] = 1;
				checkls.s[row + col] = 1;
				checkls.bs[row - col + 9] = 1;
				ft_make_path(checkls, path, row + 1, count);
				checkls.c[col] = 0;
				checkls.s[row + col] = 0;
				checkls.bs[row - col + 9] = 0;
			}
			col++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	struct s_checkls	checkls;
	int					path[10];
	int					row;
	int					count;

	count = 0;
	row = 0;
	ft_make_arr(checkls.c, 10);
	ft_make_arr(checkls.s, 19);
	ft_make_arr(checkls.bs, 19);
	ft_make_arr(path, 10);
	ft_make_path(checkls, path, row, &count);
	return (count);
}
