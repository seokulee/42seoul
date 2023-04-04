/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:26:24 by seokklee          #+#    #+#             */
/*   Updated: 2023/04/04 16:17:33 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_size;
	int			flag;
	int			i;

	read_size = 0;
	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		line = calloc(100, sizeof(char));
		while (!flag)
		{
			while (i < read_size)
			{
				if (buffer[i] == '\n')
				{
					flag = 1;
					break ;
				}
				i++;
			}
			ft_strjoin(line, buffer);
			puts(line);
		}
	}
	return (line);
}

int	main()
{
	int	fd;
	char *a;

	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		for (int i = 0; i < 5; i++)
		{
			a = get_next_line(fd);
			puts(a);
		}
		close(fd);
	}
	else
		printf("fail\n");
	return 0;
}


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

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return (i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return (i);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(size * count);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uc;

	uc = s;
	while (n--)
		*uc++ = 0;
}

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