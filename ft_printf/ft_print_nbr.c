/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:43:16 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/27 09:35:48 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	ret;

	ft_putnbr_fd(n, 1);
	if (n >= 0)
		ret = 1;
	else
		ret = 2;
	while (n / 10 != 0)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}
