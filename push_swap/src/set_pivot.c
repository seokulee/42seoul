#include "push_swap.h"

void	set_pivot(t_list *lst, int *p1, int *p2)
{
	int		h;
	int		t;
	int		m;
	int		cnt;
	t_node	*n;

	n = lst->head;
	cnt = lst->count;
	h = n->value;
	t = n->prev->value;
	while (cnt / 2 > 0)
	{
		n = n->next;
		cnt--;
	}
	m = n->value;
	*p1 = ((h + t + m) / 3) + ((h - m) / 2);
	*p2 = ((h + t + m) / 3) - ((m - t) / 2);
	sleep(2);
}