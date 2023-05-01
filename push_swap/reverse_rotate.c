#include "push_swap.h"

void	reverse_rotate(t_list *lst)
{
	if (lst->count < 2)
		return ;
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
}