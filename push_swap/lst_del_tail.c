#include "push_swap.h"

void	lst_del_tail(t_list *lst)
{
	t_node	*target;

	if (!lst || !lst->head)
		return ;
	target = lst->tail;
	if (lst->tail == lst->head)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else
	{
		lst->tail = lst->tail->prev;
		lst->tail->next = lst->head;
		lst->head->prev = lst->tail;
	}
	lst->count -= 1;
	node_del(target);
}