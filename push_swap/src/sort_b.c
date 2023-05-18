#include "push_swap.h"

void	sort_b(int cnt, t_list *a, t_list *b)
{
	int	pivot1;
	int	pivot2;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int r_cnt;

	ft_printf("!!sort_b start!!\n");
	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	if (cnt <= 3)
	{
		sort_three_b(b);
		while (cnt-- > 0)
			do_pa(a, b);
		return ;
	}
	pivot1 = set_pivots(b, 1);
	pivot2 = set_pivots(b, 2);
	while (cnt-- > 0)
	{
		if (b->head->value < pivot1)
		{
			do_rb(b);
			rb_cnt++;
		}
		else
		{
			do_pa(a, b);
			pa_cnt++;
			if (a->head->value < pivot2)
			{
				do_ra(a);
				ra_cnt++;
			}
		}
	}
	lst_print_tmp(a, b);
	if (ra_cnt >= rb_cnt)
	{
		r_cnt = rb_cnt;
		ra_cnt -= r_cnt;
		rb_cnt = 0;
	}
	else
	{
		r_cnt = ra_cnt;
		rb_cnt -= r_cnt;
		ra_cnt = 0;
	}
	sort_a(pa_cnt - ra_cnt, a, b);
	lst_print_tmp(a, b);
	while (r_cnt-- > 0)
		do_rrr(a, b);
	while (ra_cnt-- > 0)
		do_rra(a);
	while (rb_cnt-- > 0)
		do_rrb(b);
	lst_print_tmp(a, b);
	sort_a(ra_cnt, a, b);
	lst_print_tmp(a, b);
	sort_b(rb_cnt, a, b);
	lst_print_tmp(a, b);
}
