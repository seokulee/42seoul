#include "pipex.h"

static size_t	ft_count_str(char const *s, char c);
static char			**ft_free_tab(char **tab);
static void		ft_str_info(char const **s, char c, ssize_t *str_len);
static size_t	ft_abs(ssize_t num);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_size;
	size_t	i;
	ssize_t	str_len;

	tab_size = ft_count_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s || i < tab_size)
	{
		str_len = 0;
		ft_str_info(&s, c, &str_len);
		tab[i] = (char *)malloc(sizeof(char) * (ft_abs(str_len) + 1));
		if (!tab[i])
			return (ft_free_tab(tab));
		if (str_len > 0)
			ft_strlcpy(tab[i++], s - str_len, str_len + 1);
		else if (str_len < 0)
			ft_strlcpy(tab[i++], s + str_len - 1, -str_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}

static void	ft_str_info(char const **s, char c, ssize_t *str_len)
{
	while (**s && **s == c)
		(*s)++;
	while (**s && **s != c)
	{
		if (**s == '\'' || **s == '\"')
		{
			(*s)++;
			while (!(**s == '\'' || **s == '\"'))
			{
				(*s)++;
				(*str_len)++;
			}
			*str_len *= -1;
			(*s)++;
		}
		else
		{
			(*s)++;
			(*str_len)++;
		}
	}
}

static size_t	ft_count_str(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s && (*s == '\'' || *s == '\"'))
		{
			s++;
			while (*s && !(*s == '\'' || *s == '\"'))
				s++;
			s++;
		}
		else
		{
			while (*s && *s != c)
				s++;
		}
		cnt++;
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

static char	**ft_free_tab(char **tab)
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

static size_t	ft_abs(ssize_t num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
