#include "get_next_line.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*get_line(int fd, char **backup);
size_t	find_nl_idx(char *backup_fd);

char	*get_next_line(int fd)
{
	static char	*backup[257];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, backup);
	return (line);
}

char	*get_line(int fd, char **backup)
{
	ssize_t	read_size;
	char	*buffer;
	char	*tmp;
	char	*line;
	size_t	idx;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	read_size = 1;
	while (!ft_strchr(buffer, '\n') && read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(buffer);
			return (NULL);
		}
		tmp = backup[fd];
		backup[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	if (ft_strchr(backup[fd], '\n'))
	{
		idx = find_nl_idx(backup[fd]);
		line = ft_substr(backup[fd], 0, idx + 1);
		tmp = backup[fd];
		backup[fd] = ft_strdup(&(backup[fd])[idx + 1]);
		free(tmp);
		return (line);
	}
	line = ft_strdup(backup[fd]);
	free(backup[fd]);
	free(buffer);
	return (line);
}

size_t	find_nl_idx(char *backup_fd)
{
	size_t	idx;

	idx = 0;
	if (!backup_fd)
		return (0);
	while(backup_fd[idx] != '\n')
		idx++;
	return (idx);
}

//#include <stdio.h>
//#include <fcntl.h>
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
// 	// system("leaks test");
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

char	*ft_strjoin(char *s1, char *s2)
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
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
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
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uc;

	uc = s;
	while (n--)
		*uc++ = 0;
}
