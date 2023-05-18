#include "push_swap.h"

void	sort_three_b(t_list *lst)
{
	int		cnt;
	t_node	*h;
	t_node	*t;
	t_node	*b;

	cnt = lst->count;
	if (cnt < 2)
		return ;
	else if (cnt == 2)
	{
		if (lst->head->value < lst->tail->value)
			return ;
		else
			do_sa(lst);
	}
	else
	{
		h = lst->head;
		t = lst->tail;
		b = lst->head->next;
		if (h > b && h > t)
		{
			if (b > t)
			{
				do_sa(lst);
				do_rra(lst);
			}
			else
				do_ra(lst);
		}
		else if (b > h && b > t)
		{
			if (h > t)
				do_rra(lst);
			else
			{
				do_sa(lst);
				do_ra(lst);
			}
		}
		else
		{
			if (h > b)
				do_sa(lst);
		}
	}
}
