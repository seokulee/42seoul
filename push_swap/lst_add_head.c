#include "push_swap.h"

void	lst_add_head(t_list *lst, t_node *new_node)
{
	if(!lst || !new_node)
		return ;
	if (lst->head == NULL)
	{
		lst->head = new_node;
		lst->tail = new_node;
	}
	else
	{
		lst->head->prev = new_node;
		lst->tail->next = new_node;
		new_node->next = lst->head;
		new_node->prev = lst->tail;
		lst->head = new_node;
	}
	lst->count += 1;
}