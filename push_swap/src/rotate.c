#include "push_swap.h"

static void	rotate(t_list *lst)
{
	if (lst->count < 2)
		return ;
	lst->tail = lst->head;
	lst->head = lst->head->next;
}

void	do_ra(t_list *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	do_rb(t_list *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	do_rr(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
