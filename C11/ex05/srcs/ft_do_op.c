/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:39:31 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/02 11:01:58 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_do_op(char *num1, char *op, char *num2)
{
	int		(*cal[5])(int, int);
	char	*ops;

	ops = "+-*/%";
	cal[0] = add;
	cal[1] = sub;
	cal[2] = mul;
	cal[3] = div;
	cal[4] = mod;
	if (ft_is(op, ops) != -1 && ft_strlen(op) == 1)
	{
		if (ft_is(op, ops) >= 3 && ft_atoi(num2) == 0)
		{
			ft_printerr(ft_is(op, ops));
			return ;
		}
		ft_putnbr(cal[ft_is(op, ops)](ft_atoi(num1), ft_atoi(num2)));
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar('\n');
	}
}
