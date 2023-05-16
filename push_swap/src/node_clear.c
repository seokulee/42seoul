#include "push_swap.h"

void	node_clear(t_node *target)
{
	target->next = NULL;
	target->prev = NULL;
	target->value = 0;
	free (target);
	target = NULL;
}
