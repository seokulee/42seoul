#include "push_swap.h"

void	sort(t_list *a, t_list *b)
{
	int	cnt;

	cnt = a->count;
	sort_a(cnt, a, b);
}
