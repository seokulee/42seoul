#include "fdf.h"

size_t		ft_count_str(char const *s, char c);
char		**ft_free_tab(char **tab);
static void	ft_str_info(char const **s, char c, size_t *str_len);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_size;
	size_t	i;
	size_t	str_len;

	tab_size = ft_count_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s || i < tab_size)
	{
		str_len = 0;
		ft_str_info(&s, c, &str_len);
		if (str_len > 0)
		{
			tab[i] = (char *)malloc(sizeof(char) * (str_len + 1));
			if (!tab[i])
				return (ft_free_tab(tab));
			ft_strlcpy(tab[i++], s - str_len, str_len + 1);
		}
	}
	tab[i] = NULL;
	return (tab);
}

static void	ft_str_info(char const **s, char c, size_t *str_len)
{
	while (**s && **s == c)
		(*s)++;
	while (**s && **s != c)
	{
		(*s)++;
		(*str_len)++;
	}
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
