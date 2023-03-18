/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:37:26 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/25 23:04:37 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base(long long num, char *base, int i)
{
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num / i > 0)
		ft_base(num / i, base, i);
	ft_putchar(base[num % i]);
}

int	ft_is_valid(char c)
{
	if (c == '+' || c == '-')
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	j;
	long long		num;

	i = 0;
	if (!base[i])
		return ;
	while (base[i])
	{
		if (!ft_is_valid(base[i]))
			return ;
		j = 0;
		while (base[j] && j < i)
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	if (i == 1)
		return ;
	num = nbr;
	ft_base(num, base, i);
}
