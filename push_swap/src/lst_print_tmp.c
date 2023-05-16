#include "push_swap.h"
#include <stdio.h>

void	lst_print_tmp(t_list *lst)
{
	t_node	*n;

	n = lst->head;
	printf("=====\n");
	while (lst->count > 0)
	{
		printf("%d\n", n->value);
		n = n->next;
	}
	printf("=====\n");
}
