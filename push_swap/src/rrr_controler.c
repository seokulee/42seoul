#include "push_swap.h"

void	rrr_controler(int ra_cmd, int rb_cmd, t_list *a, t_list *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
