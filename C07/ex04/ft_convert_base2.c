/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:31:02 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/29 13:25:21 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	ft_match(char c, char *s)
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

int	ft_base_check(char *base)
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
	return (1);
}
