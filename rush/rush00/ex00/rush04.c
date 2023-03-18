/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:02:20 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/15 17:24:31 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_c(int x, int y, int x_num, int y_num)
{
	if (x_num == 1 || y_num == 1 || x_num == x || y_num == y)
	{
		if (x_num == 1 && y_num == 1)
			ft_putchar('A');
		else if ((x_num == x && y_num == 1) || (x_num == 1 && y_num == y))
			ft_putchar('C');
		else if (x_num == x && y_num == y)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	x_num;
	int	y_num;

	if (x < 1 || y < 1 || x > 2147483647 || y > 2147483647)
		return ;
	y_num = 1;
	while (y_num <= y)
	{
		x_num = 1;
		while (x_num <= x)
		{
			ft_print_c(x, y, x_num, y_num);
			x_num++;
		}
		ft_putchar('\n');
		y_num++;
	}
}
