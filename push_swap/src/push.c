#include "push_swap.h"

static void	push(t_list *donor, t_list *receiver)
{
	t_node	*tmp;

	tmp = node_new(donor->head->value);
	list_add_head(receiver, tmp);
	lst_del(donor);
}

void	do_pa(t_list *a, t_list *b)
{
	if (b->count == 0)
		return ;
	push(b, a);
	printf("pa\n");
}

void	do_pb(t_list *a, t_list *b)
{
	if (a->count == 0)
		return ;
	push(a, b);
	printf("pb\n");
}
