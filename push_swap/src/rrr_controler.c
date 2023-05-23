/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:12 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:13 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_controler(int ra_cmd, int rb_cmd, t_list *a, t_list *b, int opt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (opt == 1)
	{
		if (ra_cmd >= rb_cmd)
		{
			while (rb_cmd - i++ > 0)
				do_rrr(a, b);
			while (ra_cmd - rb_cmd - j++ > 0)
				do_rra(a);
		}
		else
		{
			while (ra_cmd - i++ > 0)
				do_rrr(a, b);
			while (rb_cmd - ra_cmd - j++ > 0)
				do_rrb(b);
		}
	}
	else
	{
		while (rb_cmd - i++ > 0)
			do_rrb(b);
	}
}
