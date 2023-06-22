/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:51 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/20 21:30:21 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus_count;
	int	n;

	i = 0;
	minus_count = 0;
	while (str[i] && ft_is_space(str[i]))
			i++;
	while (str[i] && ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	n = 0;
	while (str[i] && ft_is_numeric(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (minus_count % 2 == 0)
		return (n);
	else
		return (-n);
}
