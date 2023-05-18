#include "push_swap.h"

void	sort_a(int cnt, t_list *a, t_list *b)
{
	int	pivot1;
	int pivot2;
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	r_cnt;

	ft_printf("!!sort_a start!!\n");
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	if (cnt <= 3)
	{
		sort_three_a(a);
		return ;
	}
	pivot1 = set_pivots(a, 1);
	pivot2 = set_pivots(a, 2);
	while (cnt-- > 0)
	{
		if (a->head->value >= pivot2)
		{
			do_ra(a);
			ra_cnt++;
		}
		else
		{
			do_pb(a, b);
			pb_cnt++;
			if (b->head->value >= pivot1)
			{
				do_rb(b);
				rb_cnt++;
			}
		}
	}
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
	sort_b(pb_cnt - rb_cnt, a, b);
	lst_print_tmp(a, b);
}
