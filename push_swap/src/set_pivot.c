#include "push_swap.h"

void	swap_value(int *a, int *b);
t_node	*partition(t_node *begin, t_node *end);
void	quicksort(t_list *lst, t_node *head, t_node *tail);

void	set_pivot(t_list *lst, int cnt, int *p1, int *p2)
{
	t_list	*tmp;
	t_node	*lst_cursor;
	t_node	*tmp_cursor;
	int		i;
	int		j;

	tmp = list_new();
	lst_cursor = lst->head;
	i = 0;
	while (cnt - i++ > 0)
	{
		list_add_tail(tmp, node_new(lst_cursor->value));
		lst_cursor = lst_cursor->next;
	}
	quicksort(tmp, tmp->head, tmp->tail);
	tmp_cursor = tmp->head;
	j = 0;
	while (tmp->count - j++ > 0)
	{
		if (j == cnt / 3)
			*p1 = tmp_cursor->value;
		if (j == cnt / 3 * 2)
			*p2 = tmp_cursor->value;
		tmp_cursor = tmp_cursor->next;
	}
}

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
			swap_value(&(checked->value), &(cursor->value));
		}
		cursor = cursor->next;
	}
	if (checked == NULL)
		checked = begin;
	else
		checked = checked->next;
	swap_value(&(checked->value), &(cursor->value));
	return (checked);
}

void	quicksort(t_list *lst, t_node *head, t_node *tail)
{
	t_node	*p;

	if (head == NULL || head == tail)
		return ;
	p = partition(head, tail);
	if (p != head)
		quicksort(lst, head, p->prev);
	if (p != tail)
		quicksort(lst, p->next, tail);
}
