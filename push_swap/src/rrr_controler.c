/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:12 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/24 01:22:03 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_controler(int cmd[], t_list *a, t_list *b, int opt)
{
	int	i;

	i = -1;
	if (opt == 1)
	{
		if (cmd[0] >= cmd[1])
		{
			while (cmd[1] - ++i > 0)
				do_rrr(a, b);
			while (cmd[0] - i++ > 0)
				do_rra(a);
		}
		else
		{
			while (cmd[0] - ++i > 0)
				do_rrr(a, b);
			while (cmd[1] - i++ > 0)
				do_rrb(b);
		}
	}
	else
	{
		while (cmd[1] - ++i > 0)
			do_rrb(b);
	}
}
