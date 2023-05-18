#include "push_swap.h"

static void	swap(t_list *lst)
{
	int	tmp;

	if (lst->count < 2)
		return ;
	tmp = lst->head->value;
	lst->head->value = lst->head->next->value;
	lst->head->next->value = tmp;
}

void	do_sa(t_list *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	do_sb(t_list *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	do_ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
