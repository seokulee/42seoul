#include "push_swap.h"

static void	swap(t_list *lst)
{
	int	tmp;

	tmp = lst->head->value;
	lst->head->value = lst->head->next->value;
	lst->head->next->value = tmp;
}

void	do_sa(t_list *a)
{

	if (a->count < 2)
		return ;
	swap(a);
	printf("sa\n");
}

void	do_sb(t_list *b)
{

	if (b->count < 2)
		return ;
	printf("sb\n");
}

void	do_ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
