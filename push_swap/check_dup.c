#include "push_swap.h"

int	check_dup(t_list *lst, int input)
{
	t_node	*now;
	int		i;

	if (!lst)
		return (-1);
	now = lst->head;
	i = 0;
	while (i++ < lst->count)
	{
		if (input == now->value)
			return (-1);
		now = now -> next;
	}
	return (1);
}