#include "push_swap.h"

void	sort_a(t_list *a, t_list *b, int cnt)
{
	int	pivots[2];
	int	ra_cmd;
	int	rb_cmd;
	int	pb_cmd;
	int	n;

	ra_cmd = 0;
	rb_cmd = 0;
	pb_cmd = 0;
	if (cnt <= 3)
	{
		sort_small_a(a, cnt);
		return ;
	}
	set_pivot(a, cnt, &pivots[0], &pivots[1]);
	while (cnt-- > 0)
	{
		n = a->head->value;
		if (n > pivots[1])
		{
			do_ra(a);
			ra_cmd++;
		}
		else
		{
			do_pb(a, b);
			pb_cmd++;
			if (n > pivots[0])
			{
				do_rb(b);
				rb_cmd++;
			}
		}
	}
	rrr_controler(ra_cmd, rb_cmd, a, b);
	sort_a(a, b, ra_cmd);
	sort_b(a, b, rb_cmd);
	sort_b(a, b, pb_cmd - rb_cmd);
}
