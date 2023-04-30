#include "push_swap.h"

void	reverse_rotate(t_list *lst)
{
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
}