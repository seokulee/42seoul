#include "push_swap.h"

void	rotate(t_list *lst)
{
	lst->tail = lst->head;
	lst->head = lst->head->next;
}