/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:34:39 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 15:54:34 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_tab(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	if (i == 0)
		return ;
	while (i > 0)
	{
		j = 0;
		while (j + 1 < i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap_tab(&tab[j], &tab[j + 1]);
			j++;
		}
		i--;
	}
}
