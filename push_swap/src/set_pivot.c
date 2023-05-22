#include "push_swap.h"

void	set_pivot(t_list *lst, int *p1, int *p2)
{
	int		i1;
	int		i2;
	int		cnt;
	t_node	*n;

	cnt = lst->count;
	n = lst->head;
	i1 = cnt / 3;
	i2 = cnt / 3 * 2;
	while (cnt-- > 0)
	{
		if (cnt == i1)
			*p1 = n->value;
		else if (cnt == i2)
			*p2 = n->value;
		n = n->next;
	}
	if (*p1 > *p2)
	{
		cnt = *p1;
		*p1 = *p2;
		*p2 = cnt;
	}
	//sleep(2);
}