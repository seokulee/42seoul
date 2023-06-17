#include "pipex.h"

static char	*ft_strdup(const char *s1);

char	*sub_quotation(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '\"')
			s[i] = '\'';
		i++;
	}
	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_strdup(const char *s1)
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
