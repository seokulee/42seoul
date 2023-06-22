/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:50:31 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/28 22:02:41 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*num_to_word(char *str)
{
	int	len;
	int	unit;
	char	*nb;

	len = ft_strlen(str);
	unit = 0;
	while (len > 1000)
	{
		unit++;
		len /= 1000;
	}
	nb = (char *)malloc(sizeof(char) * 

	

