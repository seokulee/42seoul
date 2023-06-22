/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:26:03 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/19 10:59:20 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_nastr(char c)
{	
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_uppercase(str[i]))
				str[i] += 'a' - 'A';
		if (ft_is_nastr(str[i]))
		{
			if (ft_is_lowercase(str[i]))
			{
				if (!ft_is_nastr(str[i - 1]) || i == 0)
					str[i] -= 'a' - 'A';
			}
		}
		i++;
	}						
	return (str);
}
