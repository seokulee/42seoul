/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:26 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:55:10 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_str(char const *s, char c);
static char		**mal_err(char **tab);
static void		str_info(char const **s, char c, size_t *str_len);

char	**str_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_size;
	size_t	i;
	size_t	str_len;

	tab_size = count_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s || i < tab_size)
	{
		str_len = 0;
		str_info(&s, c, &str_len);
		if (str_len > 0)
		{
			tab[i] = (char *)malloc(sizeof(char) * (str_len + 1));
			if (!tab[i])
				return (mal_err(tab));
			ft_strlcpy(tab[i++], s - str_len, str_len + 1);
		}
	}
	tab[i] = NULL;
	return (tab);
}

static void	str_info(char const **s, char c, size_t *str_len)
{
	while (**s && **s == c)
		(*s)++;
	while (**s && **s != c)
	{
		(*s)++;
		(*str_len)++;
	}
}

static size_t	count_str(char const *s, char c)
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

static char	**mal_err(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
