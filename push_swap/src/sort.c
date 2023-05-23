/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:24 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/24 01:25:54 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a);

void	sort(t_list *a, t_list *b)
{
	int	cnt;
	int	opt;

	cnt = a->count;
	opt = 0;
	if (is_sorted(a))
		return ;
	sort_a(a, b, cnt, opt);
}

int	is_sorted(t_list *a)
{
	int		cnt;
	t_node	*cursor;

	cnt = a->count;
	cursor = a->head;
	while (--cnt > 0)
	{
		if (cursor->value > cursor->next->value)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
