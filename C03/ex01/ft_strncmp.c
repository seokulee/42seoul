/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:22 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/19 18:43:33 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (i < n - 1)
			i++;
		else
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
