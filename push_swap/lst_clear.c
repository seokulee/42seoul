#include "push_swap.h"

void	lst_clear(t_list *lst)
{
	t_node	*target;
	t_node	*next_target;

	target = lst->head;
	while (target)
	{
		next_target = target->next;
		node_del(target);
		target = next_target;
	}
	lst->count = 0;
	free(lst);
	lst = NULL;
}