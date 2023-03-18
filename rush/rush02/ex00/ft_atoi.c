/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:30:23 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/29 15:19:59 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	f_pow(int exponent)
{
	int	result;

	result = 10;
	if (exponent == 0)
		return (1);
	return (result * f_pow(exponent - 1));
}

long long	get_int_by_string(char *str)
{
	int			i;
	int			size;
	long long	result;

	i = 0;
	size = 0;
	result = 0;
	while (str[size] >= '0' && str[size] <= '9')
		size++;
	while (i < size)
	{
		result += (str[i] - '0') * f_pow(size - i - 1);
		i++;
	}
	if (result < 0)
		return (0);
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	hyphen;
	int	result;

	i = 0;
	result = 0;
	hyphen = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			hyphen++;
		else if (!(str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	result = (get_int_by_string(str + i));
	if (hyphen % 2)
		return (-result);
	return (result);
}
