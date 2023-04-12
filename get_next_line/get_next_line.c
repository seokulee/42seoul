#include "get_next_line.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_get_line(int fd, char **backup, char *buffer);
size_t	ft_find_nl_idx(char *backup_fd);

char	*get_next_line(int fd)
{
	static char	*backup[257];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = ft_strdup("");
		if (!backup[fd])
			return (0);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(fd, backup, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	if (!backup[fd])
		free(backup[fd]);
	return (line);
}

char	*ft_get_line(int fd, char **backup, char *buffer)
{
	ssize_t	read_size;
	char	*tmp;
	char	*line;
	size_t	idx;

	read_size = 1;
	while (!ft_strchr(backup[fd], '\n') && read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(backup[fd]);
			backup[fd] = NULL;
			return (NULL);
		}
		buffer[read_size] = '\0';
		tmp = backup[fd];
		backup[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!backup[fd])
			return (0);
	}
	if (ft_strchr(backup[fd], '\n'))
	{
		idx = ft_find_nl_idx(backup[fd]);
		line = ft_substr(backup[fd], 0, idx + 1);
		if (!line)
		{
			free(backup[fd]);
			backup[fd] = 0;
			return (0);
		}
		tmp = backup[fd];
		backup[fd] = ft_strdup(&(backup[fd])[idx + 1]);
		free(tmp);
		if (!backup[fd])
		{
			free(line);
			return (0);
		}
	}
	else
	{
		line = ft_strdup(backup[fd]);
		free(backup[fd]);
		backup[fd] = NULL;
		if (!line || !*line)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

size_t	ft_find_nl_idx(char *backup_fd)
{
	size_t	idx;

	idx = 0;
	if (!backup_fd)
		return (0);
	while (backup_fd[idx] != '\n')
		idx++;
	return (idx);
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
	if (c == '\0')
		return ((char *) s);
	return (NULL);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	char *str = NULL;
// 	if (argc == 2)
// 	{
// 		int fd = open(argv[1], O_RDONLY);
// 		str = get_next_line(fd);
// 	}
// 	printf("<%s>\n", str);
// 	free(str);
// 	printf("<%s>\n", str);
// 	free(str);
// 	printf("<%s>\n", str);
// 	free(str);
// 	printf("<%s>\n", str);
// 	free(str);


// }