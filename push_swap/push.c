#include "push_swap.h"

void	push(t_list *donor, t_list *recipient)
{
	t_node	*tmp;

	if (donor->count == 0)
		return ;
	tmp = node_new(donor->head->value);
	lst_add_head(recipient, tmp);
	lst_del_head(donor);
}