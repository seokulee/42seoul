/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:26:24 by seokklee          #+#    #+#             */
/*   Updated: 2023/04/06 20:40:36 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	remainder[BUFFER_SIZE + 1];
	char		*nl_ptr;
	ssize_t		read_size;
	char		*sub;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(line);
		return (NULL);
	}
	if (*remainder)
		{
			nl_ptr = ft_strchr(remainder, '\n');
			if (nl_ptr)
			{
				sub = ft_substr(remainder, 0, nl_ptr - remainder + 1);
				line = ft_strjoin_free(line, sub);
				ft_strlcpy(remainder, nl_ptr + 1, BUFFER_SIZE - (nl_ptr - remainder));
				free(sub);
				return (line);
			}
			line = ft_strdup(remainder);
			ft_bzero(remainder, BUFFER_SIZE + 1);
	}
	while (1)
	{
		if (0 < (read_size = read(fd, buffer, BUFFER_SIZE)))
		{
			nl_ptr = ft_strchr(buffer, '\n');
			if (nl_ptr)
			{
				sub = ft_substr(buffer, 0, nl_ptr - buffer + 1);
				line = ft_strjoin_free(line, sub);
				ft_strlcpy(remainder, nl_ptr + 1, BUFFER_SIZE - (nl_ptr - buffer));
				free(sub);
				break ;
			}
			else if (read_size < BUFFER_SIZE)
			{
				sub = ft_substr(buffer, 0, read_size);
				line = ft_strjoin_free(line, sub);
				free(sub);
				break ;
			}
			else
				line = ft_strjoin_free(line, buffer);
			ft_bzero(buffer, BUFFER_SIZE + 1);
		}
		else
			break ;

	}
	free(buffer);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main()
// {
// 	int	fd;
// 	char *a;

// 	if (0 < (fd = open("./test.txt", O_RDONLY)))
// 	{
// 		for (int i = 1; i <= 20; i++)
// 		{
// 			a = get_next_line(fd);
// 			printf("%d :%s", i, a);
// 		}
// 		close(fd);
// 	}
// 	else
// 		printf("fail\n");
// 	// system("leaks a.out");
// 	return 0;
// }


char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	count;

	count = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	str -= count;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uc;

	uc = s;
	while (n--)
		*uc++ = 0;
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
