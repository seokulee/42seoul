/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:30:23 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/28 21:52:32 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		result;

	i = 0;
	while (1)
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (s1[i] == '\0' && s2[i] == '\0' && result == 0)
			return (0);
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}

void	dict_error(void)
{
	write(1, "Dict_Error\n", 11);
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

char	*trim(char *str)
{
	int		i;
	int		size;
	char	*result;

	i = -1;
	size = 0;
	if (!is_numeric(str[0]))
	{
		dict_error();
		return (NULL);
	}
	while (is_numeric(str[size]))
		size++;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
	{
		dict_error();
		return (NULL);
	}
	while (++i < size)
		result[i] = str[i];
	result[i] = '\0';
	return (result);
}
