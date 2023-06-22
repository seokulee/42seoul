/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:16:47 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/02 11:10:56 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	long long	num;

	num = nb;
	if (nb < 0)
	{
		if (nb == -2147483648)
			ft_putstr("-2147483648");
		else
		{
			ft_putchar('-');
			nb *= -1;
			ft_putnbr(nb);
		}
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
