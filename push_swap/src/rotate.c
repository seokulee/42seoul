#include "push_swap.h"

static void	rotate(t_list *lst)
{
	lst->tail = lst->head;
	lst->head = lst->head->next;
}

void	do_ra(t_list *a)
{
	if (a->count < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	do_rb(t_list *b)
{
	if (b->count < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	do_rr(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
