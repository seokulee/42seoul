/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:41:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/27 09:26:37 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	s_len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	s_len = ft_strlen(s);
	write(1, s, s_len);
	return (s_len);
}
