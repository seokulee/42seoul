/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:33:36 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 18:20:08 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;

	if (*needle == '\0')
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle) || len < ft_strlen(needle))
		return (NULL);
	if (len > ft_strlen(haystack))
		size = ft_strlen(haystack);
	else
		size = len;
	while (size-- >= ft_strlen(needle))
	{
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
