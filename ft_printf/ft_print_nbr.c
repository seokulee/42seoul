/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:43:16 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/30 01:40:25 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n_len(int n);

int	ft_print_nbr(int n)
{
	char	*s;

	s = ft_itoa(n);
	if (!s)
		return (-1);
	if (write(1, s, ft_n_len(n)) < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (ft_n_len(n));
}

static int	ft_n_len(int n)
{
	int	n_len;

	if (n <= 0)
		n_len = 1;
	else
		n_len = 0;
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}
