#include "push_swap.h"
#include <stdio.h>

void	lst_print_tmp(t_list *a, t_list *b)
{
	t_node	*a_cur;
	t_node	*b_cur;
	int		a_cnt;
	int		b_cnt;

	a_cur = a->head;
	b_cur = b->head;
	a_cnt = a->count;
	b_cnt = b->count;
	printf("=====\n");
	while (a_cnt > 0 || b_cnt > 0)
	{
		if (a_cnt > 0 && b_cnt > 0)
		{
			printf("%d    %d\n", a_cur->value, b_cur->value);
			a_cur = a_cur->next;
			b_cur = b_cur->next;
			a_cnt--;
			b_cnt--;
		}
		else if (a_cnt > 0)
		{
			printf("%d      \n", a_cur->value);
			a_cur = a_cur->next;
			a_cnt--;
		}
		else
		{
			printf("      %d\n", b_cur->value);
			b_cur = b_cur->next;
			b_cnt--;
		}
	}
	printf("a    b\n");
	printf("=====\n");
}
