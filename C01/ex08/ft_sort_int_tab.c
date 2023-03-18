/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:53:47 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/17 10:19:17 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	target;
	int	tmp;

	i = 0;
	while (i < size)
	{
		target = 1;
		while (target < size - i)
		{
			if (tab[target] < tab[target - 1])
			{
				tmp = tab[target];
				tab[target] = tab[target - 1];
				tab[target - 1] = tmp;
			}
			target++;
		}
		i++;
	}	
}
