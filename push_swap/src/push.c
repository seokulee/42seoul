/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:04 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:05 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *donor, t_list *receiver)
{
	t_node	*tmp;

	tmp = node_new(donor->head->value);
	list_add_head(receiver, tmp);
	lst_del(donor);
}

void	do_pa(t_list *a, t_list *b)
{
	if (b->count == 0)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	do_pb(t_list *a, t_list *b)
{
	if (a->count == 0)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
