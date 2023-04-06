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
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*line_tmp;
	static char	tmp[BUFFER_SIZE + 1];
	int			read_size;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{

		line = ft_calloc(1024, 1);
		if (!line)
			return (NULL);
		while (1)
		{
			if (*tmp)
			{
				if (ft_strchr(tmp, '\n'))
				{
					i = (ft_strchr(tmp, '\n') - tmp);
					ft_strlcpy(line, tmp, i + 2);
					ft_strlcpy(tmp, tmp + i + 1, ft_strlen(tmp));
					return (line);
				}
				line = ft_strjoin(line, tmp);
				ft_bzero(tmp, BUFFER_SIZE + 1);
			}
			buffer = calloc(BUFFER_SIZE + 1, 1);
			if (0 < (read_size = read(fd, buffer, BUFFER_SIZE)))
			{
				//printf("buffer : %s\n",buffer);
				if (ft_strchr(buffer, '\n'))
				{
					i = (ft_strchr(buffer, '\n') - buffer);
					ft_strlcat(line, buffer, ft_strlen(line) + i + 2);
					ft_strlcpy(tmp, &buffer[i + 1], BUFFER_SIZE - i);
					break ;
				}
				else if (read_size < BUFFER_SIZE || read_size == 0)
				{
					line_tmp = ft_strdup(line);
					line = ft_strjoin(line_tmp, buffer);
					free(line_tmp);
					break ;
				}
				else
				{
					line_tmp = ft_strdup(line);
					line = ft_strjoin(line_tmp, buffer);
					free(line_tmp);
				}
			}
			else
			{
				free (line);
				free(buffer);
				return (NULL);
			}
		}
	}
	if (!line)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	return (line);
}

//int	main()
//{
//	int	fd;
//	char *a;

//	if (0 < (fd = open("./test.txt", O_RDONLY)))
//	{
//		for (int i = 1; i < 20; i++)
//		{
//			a = get_next_line(fd);
//			printf("%d : %s", i, a);
//		}
//		close(fd);
//	}
//	else
//		printf("fail\n");
//	return 0;
//}


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
	if (*s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
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
