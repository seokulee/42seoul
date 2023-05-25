/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:21:00 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:08:47 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
