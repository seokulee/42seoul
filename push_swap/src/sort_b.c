/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:18 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/24 01:25:27 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_b(t_list *a, t_list *b, int cnt, int cmds[]);
void	sort_total5_b(t_list *a, t_list *b, int opt);
void	sort_only5_b(t_list *a, t_list *b, int opt);
void	opt_check(int *opt);

void	sort_b(t_list *a, t_list *b, int cnt, int opt)
{
	int	cmds[3];

	cmds[0] = 0;
	cmds[1] = 0;
	cmds[2] = 0;
	opt_check(&opt);
	if (cnt <= 3 || cnt == 5)
	{
		if (cnt <= 3)
		{
			sort_small_b(b, cnt);
			while (cnt-- > 0)
				do_pa(a, b);
		}
		else if (cnt == 5 && b->count == 5)
			sort_total5_b(a, b, opt);
		else if (cnt == 5)
			sort_only5_b(a, b, opt);
		return ;
	}
	sorting_b(a, b, cnt, cmds);
	sort_a(a, b, cmds[2] - cmds[0], opt);
	rrr_controler(cmds, a, b, opt);
	sort_a(a, b, cmds[0], opt);
	sort_b(a, b, cmds[1], opt);
}

void	sorting_b(t_list *a, t_list *b, int cnt, int cmds[])
{
	int	pivots[2];
	int	n;

	set_pivot(b, cnt, &pivots[0], &pivots[1]);
	while (cnt-- > 0)
	{
		n = b->head->value;
		if (n <= pivots[0])
		{
			do_rb(b);
			cmds[1]++;
		}
		else
		{
			do_pa(a, b);
			cmds[2]++;
			if (n <= pivots[1])
			{
				do_ra(a);
				cmds[0]++;
			}
		}
	}
}

void	sort_total5_b(t_list *a, t_list *b, int opt)
{
	int		p;
	int		cnt;
	int		limit;
	t_node	*cursor;

	cnt = b->count;
	limit = 0;
	set_pivot5(b, 5, &p);
	while (cnt-- > 0 && limit < 3)
	{
		cursor = b->head;
		if (cursor->value >= p)
		{
			do_pa(a, b);
			limit++;
		}
		else
			do_rb(b);
	}
	sort_a(a, b, 3, opt);
	sort_b(a, b, 2, opt);
}

void	sort_only5_b(t_list *a, t_list *b, int opt)
{
	int		p;
	int		cnt;
	int		limit;
	t_node	*cursor;

	cnt = 5;
	limit = 0;
	set_pivot5(b, 5, &p);
	while (limit < 3 && cnt-- > 0)
	{
		cursor = b->head;
		if (cursor->value >= p)
		{
			do_pa(a, b);
			limit++;
		}
		else
			do_rb(b);
	}
	while (2 - cnt++ > 0)
		do_rrb(b);
	sort_a(a, b, 3, opt);
	sort_b(a, b, 2, opt);
}

void	opt_check(int *opt)
{
	if (*opt == 0)
		*opt = 1;
}
