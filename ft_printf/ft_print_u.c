/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:28:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/30 02:07:34 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n_len(long long n);
static char	*ft_itoa_u(long long num);

int	ft_print_u(unsigned int n)
{
	char		*s;
	long long	num;

	num = (long long)n;
	s = ft_itoa_u(num);
	if (!s)
		return (-1);
	if (write(1, s, ft_n_len(num)) < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (ft_n_len(num));
}

static int	ft_n_len(long long n)
{
	int	n_len;

	n_len = 1;
	while (n / 10 > 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static char	*ft_itoa_u(long long num)
{
	int			n_len;
	char		*arr;

	n_len = ft_n_len(num);
	arr = (char *)malloc(sizeof(char) * n_len + 1);
	if (!arr)
		return (NULL);
	arr[n_len--] = '\0';
	while (num / 10 > 0)
	{
		arr[n_len--] = ((num % 10) + '0');
		num /= 10;
	}
	arr[n_len] = (num % 10) + '0';
	return (arr);
}
