/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeojo <yeojo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:56:51 by yeojo             #+#    #+#             */
/*   Updated: 2023/01/15 16:41:11 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_rc(int x, int y, int x_num, int y_num)
{
	if (y_num == 1 || y_num == y)
	{
		if (x_num == 1 || x_num == x)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (x_num == 1 || x_num == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
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
			ft_print_rc(x, y, x_num, y_num);
			x_num++;
		}
		ft_putchar('\n');
		y_num++;
	}
}
