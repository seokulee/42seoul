/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:22:02 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/07 09:50:52 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int			neg;
	long long	num;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	neg = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (num > LONG_DET || ((num == LONG_DET) && \
		((neg == 0 && (*str - '0' > 7)) || (neg == 1 && (*str - '0' > 8)))))
			return (LONG_MAX + neg);
		else
			num = (num * 10) + (*str - '0');
		str++;
	}
	if (neg)
		num = -num;
	return (num);
}
