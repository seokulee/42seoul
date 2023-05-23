/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:26:20 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:26:21 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rsrr_a(t_list *lst);
void	srsrr_a(t_list *lst);
void	sort_total3_a(t_list	*lst, int f, int s, int t);
void	sort_only3_a(t_list *lst, int f, int s, int t);

void	sort_small_a(t_list *lst, int cnt)
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
		if (first > second)
			do_sa(lst);
		return ;
	}
	if (cnt == 3 && lst->count == 3)
	{
		sort_total3_a(lst, first, second, third);
		return ;
	}
	else if (cnt == 3)
	{
		sort_only3_a(lst, first, second, third);
		return ;
	}
}

void	sort_total3_a(t_list	*lst, int f, int s, int t)
{
	if (f > s && f > t)
	{
		if (s > t)
		{
			do_sa(lst);
			do_rra(lst);
		}
		else
			do_ra(lst);
	}
	else if (s > f && s > t)
	{
		if (f > t)
			do_rra(lst);
		else
		{
			do_rra(lst);
			do_sa(lst);
		}
	}
	else
	{
		if (f > s)
			do_sa(lst);
	}
}

void	sort_only3_a(t_list *lst, int f, int s, int t)
{
	if (f > s && f > t)
		{
			if (s > t)
			{
				srsrr_a(lst);
				do_sa(lst);
			}
			else
				srsrr_a(lst);
		}
		else if (s > f && s > t)
		{
			if (f > t)
			{
				rsrr_a(lst);
				do_sa(lst);
			}
			else
				rsrr_a(lst);
		}
		else
		{
			if (f > s)
				do_sa(lst);
		}
}

void	rsrr_a(t_list *lst)
{
	do_ra(lst);
	do_sa(lst);
	do_rra(lst);
}

void	srsrr_a(t_list *lst)
{
	do_sa(lst);
	do_ra(lst);
	do_sa(lst);
	do_rra(lst);
}
