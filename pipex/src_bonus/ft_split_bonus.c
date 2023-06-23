/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:01 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:45:46 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_count_str(char const *s, char c);
char			**ft_free_tab(char **tab);
static void		ft_str_info(char const **s, char c, size_t *str_len, char **p);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_size;
	size_t	i;
	size_t	str_len;
	char	*p;

	tab_size = ft_count_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s || i < tab_size)
	{
		str_len = 0;
		ft_str_info(&s, c, &str_len, &p);
		if (str_len > 0)
		{
			tab[i] = (char *)malloc(sizeof(char) * (str_len + 1));
			if (!tab[i])
				return (ft_free_tab(tab));
			ft_strlcpy(tab[i++], p, str_len + 1);
		}
	}
	tab[i] = NULL;
	return (tab);
}

static void	ft_str_info(char const **s, char c, size_t *str_len, char **p)
{
	while (**s && **s == c)
		(*s)++;
	if (**s && **s == '\'')
	{
		while (**s && **s == '\'')
			(*s)++;
		*p = (char *)*s;
		while (**s && **s != '\'')
		{
			(*s)++;
			(*str_len)++;
		}
		while (**s && **s == '\'')
			(*s)++;
	}
	else
	{
		*p = (char *)*s;
		while (**s && **s != c)
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
		if (*s && *s == '\'')
		{
			while (*s && *s == '\'')
				s++;
			while (*s && *s != '\'')
				s++;
			while (*s && *s == '\'')
				s++;
		}
		else
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
