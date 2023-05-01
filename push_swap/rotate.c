#include "push_swap.h"

void	rotate(t_list *lst)
{
	if (lst->count < 2)
		return ;
	lst->tail = lst->head;
	lst->head = lst->head->next;
}