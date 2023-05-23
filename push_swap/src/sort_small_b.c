/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:22 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:23 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rsrr_b(t_list *lst);
void	rsrrs_b(t_list *lst);
void	sort_only3_b(t_list *lst, int f, int s, int t);
void	sort_total3_b(t_list *lst, int f, int s, int t);

void	sort_small_b(t_list *lst, int cnt)
{
	int	first;
	int	second;
	int	third;

	if (!lst->head || cnt <= 1)
		return ;
	first = lst->head->value;
	second = lst->head->next->value;
	third = lst->head->next->next->value;
	if (cnt == 2)
	{
		if (first < second)
			do_sb(lst);
		return ;
	}
	if (cnt == 3 && lst->count == 3)
	{
		sort_total3_b(lst, first, second, third);
		return ;
	}
	else if (cnt == 3)
	{
		sort_only3_b(lst, first,second, third);
		return ;
	}
	
}

void	sort_only3_b(t_list *lst, int f, int s, int t)
{
	if (f > s && f > t)
	{
		if (s < t)
			rsrr_b(lst);
	}
	else if (s > f && s > t)
	{
		if (f > t)
			do_sb(lst);
		else
		{
			do_sb(lst);
			rsrr_b(lst);
		}
	}
	else
	{
		if (f > s)
			rsrrs_b(lst);
		else
		{
			do_sb(lst);
			rsrrs_b(lst);
		}
	}
}

void	sort_total3_b(t_list *lst, int f, int s, int t)
{
	if (f > s && f > t)
	{
		if (s < t)
			rsrr_b(lst);
	}
	else if (s > f && s > t)
	{
		if (f > t)
			do_sb(lst);
		else
			do_rb(lst);
	}
	else
	{
		if (f > s)
			do_rrb(lst);
		else
		{
			do_sb(lst);
			do_rrb(lst);
		}
	}
}

void	rsrr_b(t_list *lst)
{
	do_rb(lst);
	do_sb(lst);
	do_rrb(lst);
}
void	rsrrs_b(t_list *lst)
{
	do_rb(lst);
	do_sb(lst);
	do_rrb(lst);
	do_sb(lst);
}
