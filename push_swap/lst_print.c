#include "push_swap.h"
#include <stdio.h>

void	lst_print(t_list *lst)
{
	t_node	*cursur;
	int		i;

	cursur = lst->head;
	i = 0;
	while (i++ < lst->count)
	{
		printf("%d ",cursur->value);
		cursur = cursur->next;
	}
	printf("\n");
}