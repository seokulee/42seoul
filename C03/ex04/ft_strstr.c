/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:43:10 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/19 18:44:49 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	f;

	i = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		f = 0;
		while (str[i + f] == to_find[f])
		{
			f++;
			if (!to_find[f])
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
