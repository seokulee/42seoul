#include "push_swap.h"

void	push(t_list *donor, t_list *recipient)
{
	t_node	*tmp;

	tmp = node_new(donor->head->value);
	lst_add_head(recipient, tmp);
	lst_del_head(donor);
}