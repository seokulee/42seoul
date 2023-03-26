/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:17:24 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/26 17:59:07 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_parsing(const char *format, va_list ap)
{
	char	*conversions;
	int		len;

	conversions = "cspdiuxX%%";
	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr(conversions, *(format + 1)))
		{
			if (*(format + 1) == 'c')
				len += ft_print_char(va_arg(ap, int));
			else if (*(format + 1) == '%')
				len += ft_print_char('%');
			else if (*(format + 1) == 's')
				len += ft_print_str(va_arg(ap, char *));
			else if (*(format + 1) == 'p')
				len += ft_print_ptr(va_arg(ap, unsigned long));
			else if (*(format + 1) == 'i' || *(format + 1) == 'd')
				len += ft_print_nbr(va_arg(ap, int));
			else if (*(format + 1) == 'u')
				len += ft_print_u(va_arg(ap, unsigned int));
			else if (*(format + 1) == 'x' || *(format + 1) == 'X')
				len += ft_print_hex(va_arg(ap, long long), *(format + 1));
			format++;
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	return (len);
}