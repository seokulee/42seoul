/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:27:25 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 20:59:15 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_is_numeric(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
