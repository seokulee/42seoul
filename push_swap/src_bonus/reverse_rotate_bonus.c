/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:08 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/26 21:53:31 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	do_rrb(t_list *b)
{
	if (b->count < 2)
		return ;
	reverse_rotate(b);
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
}
