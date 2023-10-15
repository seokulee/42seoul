#include "get_next_line.h"

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
