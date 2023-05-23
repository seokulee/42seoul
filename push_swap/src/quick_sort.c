/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:06 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/24 01:23:42 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_value(int *a, int *b)
{
	int	tmp;

	if (a == b)
		return ;
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
