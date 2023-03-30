/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:37:57 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/30 01:54:57 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(int n);

char	*ft_itoa(int n)
{
	long long	num;
	int			n_len;
	char		*arr;

	num = (long long)n;
	n_len = ft_n_len(n);
	arr = (char *)malloc(sizeof(char) * n_len + 1);
	if (!arr)
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
		num *= -1;
	}
	arr[n_len--] = '\0';
	while (num / 10 > 0)
	{
		arr[n_len--] = ((num % 10) + '0');
		num /= 10;
	}
	arr[n_len] = (num % 10) + '0';
	return (arr);
}

static int	ft_n_len(int n)
{
	int	n_len;

	n_len = 0;
	if (n <= 0)
		n_len = 1;
	else
		n_len = 0;
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}
