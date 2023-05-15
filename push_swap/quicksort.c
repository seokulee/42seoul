#include "push_swap.h"
#include <stdio.h>

void	swap_value(int *a, int *b)
{
	if (a == b)
		return ;
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_node	*partition(t_node *begin, t_node *end)
{
	t_node	*cursor;
	t_node	*checked;
	int		pivot;

	cursor = begin;
	checked = NULL;
	pivot = end->value;
	while (cursor != end)
	{
		if (cursor->value <= pivot)
		{
			if (checked == NULL)
				checked = begin;
			else
				checked = checked->next;
			printf("---c---\n%d %d\n",checked->value, cursor->value);
			swap_value(&(checked->value), &(cursor->value));
			//printf("---every change---\n");
			//printf("%d %d %d %d %d %d\n", begin->value, begin->next->value, begin->next->next->value, begin->next->next->next->value, begin->next->next->next->next->value, begin->next->next->next->next->next->value);

		}
		cursor = cursor->next;
	}
	if (checked == NULL)
		checked = begin;
	else
		checked = checked->next;
	printf("---c---\n%d %d\n",checked->value, cursor->value);
	swap_value(&(checked->value), &(cursor->value));
	//printf("---final one qs---\n");
	printf("%d %d %d %d %d %d\n", begin->value, begin->next->value, begin->next->next->value, begin->next->next->next->value, begin->next->next->next->next->value, begin->next->next->next->next->next->value);
	sleep(3);
	return (checked);
}

void	quicksort(t_node *head, t_node *tail)
{
	t_node	*p;

	if (head == NULL || head == tail)
		return ;
	p = partition(head, tail);
	printf("LP: \nbegin : %d end:%d\n",head->value, p->prev->value);
	if (p == head)
		return ;
	quicksort(head, p->prev);
	printf("LP: \nbegin : %d end:%d\n",p->next->value, tail->value);
	if (p == tail)
		return ;
	quicksort(p->next, tail);
}