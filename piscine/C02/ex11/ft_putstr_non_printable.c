/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:22:38 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/21 12:03:30 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_hex_one(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_hex_more(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c / 16 > 0)
		ft_hex_more(c / 16);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] >= 127)
		{
			ft_putchar('\\');
			if (str[i] / 16 > 0)
				ft_hex_more(str[i]);
			else
				ft_hex_one(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
