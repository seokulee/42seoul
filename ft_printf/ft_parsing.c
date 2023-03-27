/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:17:24 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/27 14:30:04 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parsing(const char *format, va_list ap, int *len)
{
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspiduxX%%", *(++format)))
		{
			if (*format == 'c')
				*len += ft_print_char(va_arg(ap, int));
			else if (*format == '%')
				*len += ft_print_char('%');
			else if (*format == 's')
				*len += ft_print_str(va_arg(ap, char *));
			else if (*format == 'p')
				*len += ft_print_ptr(va_arg(ap, unsigned long));
			else if (*format == 'i' || *format == 'd')
				*len += ft_print_nbr(va_arg(ap, int));
			else if (*format == 'u')
				*len += ft_print_u(va_arg(ap, unsigned int));
			else if (*format == 'x' || *format == 'X')
				*len += ft_print_hex(va_arg(ap, unsigned int ), *format);
		}
		else
			*len += ft_print_char(*format);
		format++;
	}
}
