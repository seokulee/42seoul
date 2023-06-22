/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:59:19 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/29 16:42:14 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_in(str[i], charset) && ft_is_in(str[i + 1], charset))
			word_count++;
		i++;
	}
	return (word_count);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

void	ft_put_words(char **words, char *str, char *charset)
{
	int		i;
	int		j;
	int		word_index;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		if (ft_is_in(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!ft_is_in(str[i + j], charset))
				j++;
			words[word_index] = (char *)malloc(sizeof(char) * (j + 1));
			words[word_index] = ft_strncpy(words[word_index], &str[i], j);
			words[word_index][j] = '\0';
			i += j;
			word_index++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		word_count;

	word_count = ft_count_word(str, charset);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	words[word_count] = 0;
	ft_put_words(words, str, charset);
	return (words);
}
