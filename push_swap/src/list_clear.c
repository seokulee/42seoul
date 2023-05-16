#include "push_swap.h"

void	list_clear(t_list *lst)
{
	t_node	*cursor;
	t_node	*tmp;

	cursor = lst->head;
	while (lst->count > 0)
	{
		tmp = cursor->next;
		node_clear(cursor);
		cursor = tmp;
		lst->count -= 1;
	}
	free(lst);
	lst = NULL;
}
