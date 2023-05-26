/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:08 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/26 21:56:32 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list *lst)
{
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
}

void	do_rra(t_list *a)
{
	if (a->count < 2)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_list *b)
{
	if (b->count < 2)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_list *a, t_list *b)
{
	if (a->count < 2 && b->count < 2)
		return ;
	else if (a->count < 2)
		reverse_rotate(b);
	else if (b->count < 2)
		reverse_rotate(a);
	else
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	write(1, "rrr\n", 4);
}
