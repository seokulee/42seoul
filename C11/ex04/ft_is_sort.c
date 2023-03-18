/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:16:03 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/02 13:05:30 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	dsc;

	i = 0;
	asc = 0;
	dsc = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			dsc++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			asc++;
		i++;
	}
	if (asc == i || dsc == i)
		return (1);
	return (0);
}
