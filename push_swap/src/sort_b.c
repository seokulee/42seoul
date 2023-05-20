#include "push_swap.h"

void	sort_b(t_list *a, t_list *b, int cnt)
{
	int	pivot1;
	int	pivot2;
	int	ra_cmd;
	int	rb_cmd;
	int	pa_cmd;
	int	n;

	ra_cmd = 0;
	rb_cmd = 0;
	pa_cmd = 0;
	if (cnt <= 3)
	{
		sort_small_b(b, cnt);
		while (cnt-- > 0)
			do_pa(a, b);
		return ;
	}
	set_pivot(b, &pivot1, &pivot2);
	while (cnt-- > 0)
	{
		n = b->head->value;
		if (n <= pivot1)
		{
			do_rb(b);
			rb_cmd++;
		}
		else
		{
			do_pa(a, b);
			pa_cmd++;
			if (n <= pivot2)
			{
				do_ra(a);
				ra_cmd++;
			}
		}
	}
	lst_print_tmp(a, b);
	sort_a(a, b, pa_cmd - ra_cmd);
	lst_print_tmp(a, b);
	rrr_controler(ra_cmd, rb_cmd, a, b);
	lst_print_tmp(a, b);
	sort_a(a, b, ra_cmd);
	lst_print_tmp(a, b);
	sort_b(a, b, rb_cmd);
	lst_print_tmp(a, b);
}
