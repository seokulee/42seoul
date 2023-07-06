/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:25:36 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 18:20:18 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	count;
	char	*result;

	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	count = s_len - start;
	if (count > len)
		count = len;
	if (!*s)
		count = 0;
	result = (char *)malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	s += start;
	ft_strlcpy(result, s, count + 1);
	return (result);
}
