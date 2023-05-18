#include "push_swap.h"

void	lst_del(t_list *lst)
{
	t_node	*target;

	if (!lst || !lst->head)
		return ;
	target = lst->head;
	if (lst->head == lst->tail)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else
	{
		lst->head = lst->head->next;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
	lst->count -= 1;
	node_clear(target);
}
