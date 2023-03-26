/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:43:16 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/25 16:48:58 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr(int n)
{
	int	ret;

	ft_putnbr_fd(n, 1);
	ret = 1;
	while ((n /= 10) > 0)
	ret++;
	return (ret);
}