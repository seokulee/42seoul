#include "push_swap.h"

void	reverse_rotate(t_list *lst)
{
	if (lst->count < 2)
		return ;
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
}

void	do_rra(t_list *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	do_rrb(t_list *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	do_rrr(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rr\n");
}