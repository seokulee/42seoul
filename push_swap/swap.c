#include "push_swap.h"

void	swap(t_list *lst)
{
	//t_node	*original_head;
	int tmp;

	//original_head = lst->head;
	//lst->head = original_head->next;
	//if (lst->count == 2)
	//{
	//	lst->tail = original_head;
	//	return ;
	//}
	//original_head->next = lst->head->next;
	//lst->head->next->prev = original_head;
	//lst->head->next = original_head;
	//original_head->prev = lst->head;
	//lst->head->prev = lst->tail;
	//lst->tail->next = lst->head;
	tmp = lst->head->value;
	lst->head->value = lst->head->next->value;
	lst->head->next->value = tmp;
}