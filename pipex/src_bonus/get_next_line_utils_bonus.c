/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:09 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:37:10 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	count;

	if (!s1)
		return (NULL);
	count = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	str -= count;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}
