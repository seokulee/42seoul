/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:47:32 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/25 23:21:09 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_include(char c, char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_valid(char c)
{
	if ((c >= 9 && c <= 13) || c == 32 || c == '-' || c == '+')
		return (0);
	return (1);
}

int	ft_base(char *str, char *base, int n)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (ft_include(str[i], base) != -1)
			result = (result * n) + ft_include(str[i], base);
		else
			break ;
		i++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!base[i])
		return (0);
	while (base[i])
	{
		if (!ft_is_valid(base[i]))
			return (0);
		j = 0;
		while (base[j] && j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (ft_base(str, base, i));
}
