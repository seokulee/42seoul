#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	*get_path(char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
	}
	return (0);
}
