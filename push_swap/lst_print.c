#include "push_swap.h"
#include <stdio.h>

void	lst_print(t_list *lst)
{
	t_node	*cursur;

	cursur = lst->head;
	while (1)
	{
		printf("%d ",cursur->value);
		cursur = cursur->next;
		if (cursur == lst->head)
			break ;
	}
}