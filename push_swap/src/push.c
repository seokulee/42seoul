#include "push_swap.h"

static void	push(t_list *donor, t_list *receiver)
{
	t_node	*tmp;

	if (donor->count == 0)
		return ;
	tmp = node_new(donor->head->value);
	list_add_head(receiver, tmp);
	lst_del(donor);
}

void	do_pa(t_list *a, t_list *b)
{
	push(b, a);
	printf("pa\n");
}

void	do_pb(t_list *a, t_list *b)
{
	push(a, b);
	printf("pb\n");
}
