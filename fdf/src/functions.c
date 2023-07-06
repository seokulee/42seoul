#include "fdf.h"

void	ft_open(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		terminate(ERR_OPEN, 1);
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		terminate(ERR_CLOSE, 1);
}

char	**ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

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
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i--;
	while (++i < s1_len + s2_len)
		str[i] = s2[i - s1_len];
	str[i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_count_str(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		cnt++;
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

void	terminate(char *msg, int exit_num)
{
	write(2, msg, ft_strlen(msg));
	exit(exit_num);
}
