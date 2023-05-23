/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:25:43 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:25:44 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_add_head(t_list *lst, t_node *node)
{
	if (!lst || !node)
		return ;
	if (lst->head == NULL)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		node->prev = lst->tail;
		node->next = lst->head;
		lst->head->prev = node;
		lst->head = node;
	}
	lst->count += 1;
}
