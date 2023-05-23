/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:14 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:15 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_list *lst, int cnt, int *p1, int *p2)
{
	t_list	*tmp;
	t_node	*cursor;
	int		i;
	int		j;

	tmp = list_new();
	cursor = lst->head;
	i = 0;
	while (cnt - i++ > 0)
	{
		list_add_tail(tmp, node_new(cursor->value));
		cursor = cursor->next;
	}
	quicksort(tmp, tmp->head, tmp->tail);
	cursor = tmp->head;
	j = 0;
	while (tmp->count - j++ > 0)
	{
		if (j == cnt / 3)
			*p1 = cursor->value;
		if (j == cnt / 3 * 2)
			*p2 = cursor->value;
		cursor = cursor->next;
	}
	list_clear(tmp);
}

void	set_pivot5(t_list *lst, int cnt, int *p)
{
	t_list	*tmp;
	t_node	*cursor;
	int		i;

	tmp = list_new();
	cursor = lst->head;
	i = 0;
	while (cnt - i++ > 0)
	{
		list_add_tail(tmp, node_new(cursor->value));
		cursor = cursor->next;
	}
	quicksort(tmp, tmp->head, tmp->tail);
	*p = tmp->head->next->next->value;
	list_clear(tmp);
}