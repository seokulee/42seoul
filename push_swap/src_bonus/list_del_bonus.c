/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:25:49 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:09:04 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	lst_del(t_list *lst)
{
	t_node	*target;

	if (!lst || !lst->head)
		return ;
	target = lst->head;
	if (lst->head == lst->tail)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else
	{
		lst->head = lst->head->next;
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
	}
	lst->count -= 1;
	node_clear(target);
}
