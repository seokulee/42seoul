/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:51:11 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/30 13:17:08 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_n_len(unsigned int n);
static char	*ft_itoh(unsigned int n);
static void	ft_toupper_arr(char *s);

int	ft_print_hex(unsigned int num, char x)
{
	char	*s;

	s = ft_itoh(num);
	if (!s)
		return (-1);
	if (x == 'X')
		ft_toupper_arr(s);
	if (write(1, s, ft_n_len(num)) < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (ft_n_len(num));
}

static int	ft_n_len(unsigned int n)
{
	int	n_len;

	n_len = 1;
	while (n / 16 > 0)
	{
		n_len++;
		n /= 16;
	}
	return (n_len);
}

static char	*ft_itoh(unsigned int n)
{
	long long	num;
	int			n_len;
	char		*hex;
	char		*arr;

	num = (long long)n;
	hex = "0123456789abcdef";
	n_len = ft_n_len(n);
	arr = (char *)malloc(sizeof(char) * n_len + 1);
	if (!arr)
		return (NULL);
	arr[n_len--] = '\0';
	while (num / 16 > 0)
	{
		arr[n_len--] = (hex[num % 16]);
		num /= 16;
	}
	arr[n_len] = (hex[num % 16]);
	return (arr);
}

static void	ft_toupper_arr(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}
