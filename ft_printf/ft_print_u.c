/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:28:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/26 17:37:23 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_u_rc(unsigned int num, int *len);

int	ft_print_u(unsigned int num)
{
	int	len;

	len = 1;
	ft_print_u_rc(num, &len);
	return (len);
}

static void	ft_print_u_rc(unsigned int num, int *len)
{
	char	c;

	if (num / 10 > 0)
	{
		*len += 1;
		ft_print_u_rc(num / 10, len);
	}
	c = (num % 10) + '0';
	write (1, &c, 1);
}