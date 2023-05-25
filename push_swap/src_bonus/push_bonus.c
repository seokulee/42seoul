/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:04 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:09:23 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	do_pb(t_list *a, t_list *b)
{
	if (a->count == 0)
		return ;
	push(a, b);
}
