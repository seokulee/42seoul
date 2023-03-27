/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:49:10 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/26 18:10:59 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr_hex(unsigned long ptr, int *len);

int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	ft_print_ptr_hex(ptr, &len);
	return (len);
}

static void	ft_print_ptr_hex(unsigned long ptr, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if ((ptr >> 4) > 0)
		ft_print_ptr_hex(ptr >> 4, len);
	write(1, &hex[ptr % 16], 1);
	*len += 1;
}
