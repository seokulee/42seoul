/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:34:46 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/24 18:00:24 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb *= ft_recursive_power(nb, --power));
}

int	ft_sqrt(int nb)
{
	int	i;
	int	i_count;
	int	result;

	i = 2;
	result = 1;
	while (i <= nb / i)
	{	
		i_count = 0;
		while (nb % i == 0)
		{
			i_count++;
			nb /= i;
		}
		if (i_count > 0 && i_count % 2 == 0)
			result *= ft_recursive_power(i, (i_count / 2));
		else if (i_count > 0 && i_count % 2 != 0)
			return (0);
		i++;
	}
	if (nb != 1 && result == 1)
		return (0);
	else
		return (result);
}
