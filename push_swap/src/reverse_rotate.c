#include "push_swap.h"

static void	reverse_rotate(t_list *lst)
{
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
}

void	do_rra(t_list *a)
{
	if (a->count < 2)
		return ;
	reverse_rotate(a);
	printf("rra\n");
}

void	do_rrb(t_list *b)
{
	if (b->count < 2)
		return ;
	reverse_rotate(b);
	printf("rrb\n");
}

void	do_rrr(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
