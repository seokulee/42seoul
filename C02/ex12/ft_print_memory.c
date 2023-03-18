/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:23:20 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/21 16:00:59 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prt_hex(char *addr)
{
	char	*hex;
	char	c;
	int		i;

	hex = "0123456789abcdef";
	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		c = addr[i];
		write(1, &hex[c / 16], 1);
		write(1, &hex[c % 16], 1);
		if (c == '\0')
			break ;
	}
	while (i++ < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
}

void	ft_prt_cont(char *addr)
{
	char	*p_addr;
	int		i;

	i = 0;
	p_addr = &addr[0];
	write(1, " ", 1);
	while (i < 16 && p_addr[i])
	{
		if (p_addr[i] >= ' ' && p_addr[i] <= 127)
			write(1, &p_addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	ft_hex(unsigned long long addr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr / 16 > 0)
		ft_hex(addr / 16);
	write(1, &hex[addr % 16], 1);
}

void	ft_prt_addr(unsigned long long addr)
{
	unsigned long long	num;
	int					i;

	num = addr;
	i = 1;
	while (i < 16)
	{
		if (num / 16 == 0)
			write(1, "0", 1);
		num /= 16;
		i++;
	}
	ft_hex(addr);
	write(1, ":", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;

	c = addr;
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			ft_prt_addr((unsigned long long)addr + i);
			ft_prt_hex((char *)addr + i);
			ft_prt_cont((char *)addr + i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (addr);
}
