#include "minirt.h"

char	*ft_strtok(char *str, char *delim)
{
	static char	*next_str;
	static int	next_str_len;
	char		*ret;
	int			idx;

	if (str || (str = next_str))
	{
		while (*str && ft_strchr(delim, *str))
			str++;
		if (*str == '\0')
			return (NULL);
		ret = str;
		idx = 0;
		while (str[idx] && !ft_strchr(delim, str[idx]))
			idx++;
		if (str[idx] == '\0')
			next_str = NULL;
		else
		{
			str[idx] = '\0';
			next_str = str + idx + 1;
		}
		return (ret);
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

int	ft_open(int *fd, char *open_file)
{
	*fd = open(open_file, O_RDONLY);
	if (*fd < 0)
		return (-1);
	return (1);
}

int	ft_close(int fd)
{
	if (close(fd) < 0)
		return (-1);
	return (1);
}
