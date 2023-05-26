/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:10 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/26 21:53:14 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_list *lst)
{
	lst->tail = lst->head;
	lst->head = lst->head->next;
}

void	do_ra(t_list *a)
{
	if (a->count < 2)
		return ;
	rotate(a);
}

void	do_rb(t_list *b)
{
	if (b->count < 2)
		return ;
	rotate(b);
}

void	do_rr(t_list *a, t_list *b)
{
	if (a->count < 2 && b->count < 2)
		return ;
	else if (a->count < 2)
		rotate(b);
	else if (b->count < 2)
		rotate(a);
	else
	{
		rotate(a);
		rotate(b);
	}
}
