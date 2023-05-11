/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/29 23:58:00 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	s_len;

	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		s_len = 6;
	}
	else
	{
		s_len = ft_strlen(s);
		if (write(1, s, s_len) < 0)
			return (-1);
	}
	return (s_len);
}
