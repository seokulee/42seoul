/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:52:41 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/15 17:34:13 by yeojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

long	ft_atoi(const char *s)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (s[i])
		return (0);
	return (num);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc > 3)
		return (1);
	else if (argc < 3)
		return (-1);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
