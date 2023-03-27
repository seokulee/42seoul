/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:51:11 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/27 13:52:26 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex_rc(long long num, int *hex_len, char *hex);

int	ft_print_hex(unsigned int num, char x)
{
	int		hex_len;
	char	*hex_lc;
	char	*hex_uc;

	hex_len = 0;
	hex_lc = "0123456789abcdef";
	hex_uc = "0123456789ABCDEF";
	if (x == 'x')
		ft_print_hex_rc(num, &hex_len, hex_lc);
	else if (x == 'X')
		ft_print_hex_rc(num, &hex_len, hex_uc);
	return (hex_len);
}

static void	ft_print_hex_rc(long long num, int *hex_len, char *hex)
{
	if (*hex_len < 8 && num != 0)
	{
		if (num > -1)
		{
			*hex_len += 1;
			ft_print_hex_rc(num >> 4, hex_len, hex);
		}
		else if (num <= -1)
		{
			*hex_len += 1;
			ft_print_hex_rc(num >> 4, hex_len, hex);
		}
		else
			*hex_len += 1;
		write(1, &hex[num & 15], 1);
	}
	else if (*hex_len == 0 && num == 0)
	{
		*hex_len += 1;
		write(1, &hex[0], 1);
	}
	return ;
}
