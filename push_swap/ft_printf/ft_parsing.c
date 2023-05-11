/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:17:24 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/30 11:44:25 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_by_conversion(char c, va_list ap);

int	ft_parsing(const char *format, va_list ap)
{
	int	len;
	int	read_size;

	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspiduxX%%", *(++format)))
			read_size = ft_by_conversion(*format, ap);
		else
			read_size = ft_print_char(*format);
		if (read_size < 0)
			return (-1);
		len += read_size;
		format++;
	}
	return (len);
}

static int	ft_by_conversion(char c, va_list ap)
{
	int	len;

	if (c == 'c')
		len = ft_print_char(va_arg(ap, int));
	else if (c == '%')
		len = ft_print_char('%');
	else if (c == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		len = ft_print_ptr(va_arg(ap, unsigned long));
	else if (c == 'i' || c == 'd')
		len = ft_print_nbr(va_arg(ap, int));
	else if (c == 'u')
		len = ft_print_u(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_print_hex(va_arg(ap, long long), c);
	else
		len = 0;
	return (len);
}
