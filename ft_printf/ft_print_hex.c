/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:51:11 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/30 02:54:19 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex_rc(int num, int *len, char *hex);

int	ft_print_hex(int num, char x)
{
	int		len;
	char	*hex_lc;

	len = 0;
	hex_lc = "0123456789abcdef";
	if (x == 'x')
		ft_print_hex_rc(num, &len, hex_lc);
	return (len);
}

static void	ft_print_hex_rc(int num, int *len, char *hex)
{
	if (*len == -1)
		return ;
	*len += 1;
	if (num / 16 != 0)
		ft_print_hex_rc(num / 16, len, hex);
	if (write(1, &hex[num % 16], 1) < 0)
	{
		*len = -1;
		return ;
	}
	return ;
}
