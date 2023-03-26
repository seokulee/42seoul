/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:45 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/26 17:49:01 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	// char	*tmp;
	int		print_len;

	va_start(ap, format);
	// tmp = ft_strdup(format);
	print_len = ft_parsing(format, ap);
	va_end(ap);
	// free(tmp);
	return (print_len);
}
