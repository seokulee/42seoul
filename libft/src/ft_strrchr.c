/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:20:12 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 18:20:12 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	s += s_len;
	while (s_len-- > 0)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s--;
	}
	if (*s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}
