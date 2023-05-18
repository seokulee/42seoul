#include "push_swap.h"

int	set_pivots(t_list *lst, int index)
{
	int		cnt;
	int		max;
	int		min;
	t_node	*n;

	cnt = lst->count;
	n = lst->head;
	max = n->value;
	min = n->value;
	while (cnt-- > 0)
	{
		if (n->value > max)
			max = n->value;
		else if (n->value < min)
			min = n->value;
		n = n->next;
	}
	return ((max + min) / 3 * index);
}
