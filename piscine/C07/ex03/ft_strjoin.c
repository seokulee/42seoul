/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:49:19 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/29 18:31:46 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*(str++))
		length++;
	return (length);
}

char	*ft_mycat(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (s1);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		length += ft_strlen(sep);
		i++;
	}
	length -= ft_strlen(sep);
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		length;
	int		i;

	if (size == 0)
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	length = ft_total_length(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		str = ft_mycat(str, strs[i]);
		if (i + 1 < size)
			str = ft_mycat(str, sep);
		i++;
	}
	*str = '\0';
	return (str - length);
}
