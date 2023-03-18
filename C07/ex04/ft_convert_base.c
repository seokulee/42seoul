/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:29:15 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/29 18:51:31 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_match(char c, char *s);
int	ft_is_valid(char c);
int	ft_base_check(char *base);

int	ft_atoi(char *nbr, char *base_from, int from_len)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nbr[i] && ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32))
		i++;
	while (nbr[i] && (nbr[i] == '-' || nbr[i] == '+'))
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i])
	{
		if (ft_match(nbr[i], base_from) != -1)
			result = (result * from_len) + ft_match(nbr[i], base_from);
		else
			break ;
		i++;
	}
	return (result * sign);
}

void	ft_putnbr_base(long long num, char *base, char *str, int index)
{
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
		while (index >= 1)
		{
			str[index] = base[num % ft_strlen(base)];
			num = num / ft_strlen(base);
			index--;
		}
	}
	else
	{
		while (index >= 0)
		{
			str[index] = base[num % ft_strlen(base)];
			num = num / ft_strlen(base);
			index--;
		}
	}
}

int	ft_result_length(long long num, int to_len)
{
	int	result;

	result = 1;
	if (num < 0)
	{
		result++;
		num = num * -1;
	}
	while (num / to_len > 0)
	{
		result++;
		num /= to_len;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	int			to_len;
	int			from_len;
	long long	num;
	int			i;

	to_len = ft_strlen(base_to);
	from_len = ft_strlen(base_from);
	if (!(ft_base_check(base_from) && ft_base_check(base_to)))
		return (NULL);
	num = ft_atoi(nbr, base_from, from_len);
	i = ft_result_length(num, to_len);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		free(str);
	ft_putnbr_base(num, base_to, str, i - 1);
	str[i] = '\0';
	return (str);
}
