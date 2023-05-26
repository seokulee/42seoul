/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:32 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/26 21:52:58 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_list *lst)
{
	int	tmp;

	tmp = lst->head->value;
	lst->head->value = lst->head->next->value;
	lst->head->next->value = tmp;
}

void	do_sa(t_list *a)
{
	if (a->count < 2)
		return ;
	swap(a);
}

void	do_sb(t_list *b)
{
	if (b->count < 2)
		return ;
	swap(b);
}

void	do_ss(t_list *a, t_list *b)
{
	if (a->count < 2 && b->count < 2)
		return ;
	else if (a->count < 2)
		swap(b);
	else if (b->count < 2)
		swap(a);
	else
	{
		swap(a);
		swap(b);
	}
}
