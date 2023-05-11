/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:49:10 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/29 23:59:20 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr_hex(unsigned long ptr, int *len, char *hex);

int	ft_print_ptr(unsigned long ptr)
{
	int		len;
	char	*hex;

	len = 2;
	hex = "0123456789abcdef";
	if (write(1, "0x", 2) < 0)
		return (-1);
	ft_print_ptr_hex(ptr, &len, hex);
	return (len);
}

static void	ft_print_ptr_hex(unsigned long ptr, int *len, char *hex)
{
	if (*len == -1)
		return ;
	*len += 1;
	if ((ptr >> 4) > 0)
		ft_print_ptr_hex(ptr >> 4, len, hex);
	if (write(1, &hex[ptr % 16], 1) < 0)
	{
		*len = -1;
		return ;
	}
	return ;
}
