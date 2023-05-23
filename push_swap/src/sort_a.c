/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:16 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:17 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_a(t_list *a, t_list *b, int cnt, int cmds[]);
void	sort_total5_a(t_list *a, t_list *b, int opt);
void	sort_only5_a(t_list *a, t_list *b, int opt);

void	sort_a(t_list *a, t_list *b, int cnt, int opt)
{
	int	cmds[3];

	cmds[0] = 0;
	cmds[1] = 0;
	cmds[2] = 0;
	if (cnt <= 3)
	{
		sort_small_a(a, cnt);
		return ;
	}
	if (cnt == 5 && a->count == 5)
	{
		sort_total5_a(a, b, opt);
		return ;
	}
	else if (cnt == 5)
	{
		sort_only5_a(a, b, opt);
		return ;
	}
	sorting_a(a, b, cnt, cmds);
	rrr_controler(cmds[0], cmds[1], a, b, opt);
	sort_a(a, b, cmds[0], opt);
	sort_b(a, b, cmds[1], opt);
	sort_b(a, b, cmds[2] - cmds[1], opt);
}

void	sorting_a(t_list *a, t_list *b, int cnt, int cmds[])
{
	int	pivots[2];
	int	n;

	set_pivot(a, cnt, &pivots[0], &pivots[1]);
	while (cnt-- > 0)
	{
		n = a->head->value;
		if (n > pivots[1])
		{
			do_ra(a);
			cmds[0]++;
		}
		else
		{
			do_pb(a, b);
			cmds[2]++;
			if (n > pivots[0])
			{
				do_rb(b);
				cmds[1]++;
			}
		}
	}
}

void	sort_total5_a(t_list *a, t_list *b, int opt)
{
	int		p;
	int		cnt;
	int		limit;
	t_node	*cursor;

	cnt = a->count;
	limit = 0;
	set_pivot5(a, 5, &p);
	while (cnt-- > 0 && limit < 2)
	{
		cursor = a->head;
		if (cursor->value < p)
		{
			do_pb(a, b);
			limit++;
		}
		else
			do_ra(a);
	}
	sort_a(a, b, 3, opt);
	sort_b(a, b, 2, opt);
}

void	sort_only5_a(t_list *a, t_list *b, int opt)
{
	int		p;
	int		cnt;
	int		limit;
	t_node	*cursor;

	cnt = 5;
	limit = 0;
	set_pivot5(a, 5, &p);
	while (limit < 2 && cnt-- > 0)
	{
		cursor = a->head;
		if (cursor->value < p)
		{
			do_pb(a, b);
			limit++;
		}
		else
			do_ra(a);
	}
	while (3 - cnt++ > 0)
		do_rra(a);
	sort_a(a, b, 3, opt);
	sort_b(a, b, 2, opt);
}
