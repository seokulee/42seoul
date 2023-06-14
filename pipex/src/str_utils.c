#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len + 1)
		return (src_len + dstsize);
	i = 0;
	if (dstsize > dst_len + 1)
	{
		while (*src && dst_len + i + 1 < dstsize)
			*(dst + dst_len + i++) = *src++;
	}
	*(dst + dst_len + i) = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
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
