#include "push_swap.h"

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
	else
	{
		if (first > second && first > third)
		{
			if (second < third)
			{
				do_rb(lst);
				do_sb(lst);
				do_rrb(lst);
			}
		}
		else if (second > first && second > third)
		{
			if (first > third)
				do_sb(lst);
			else
			{
				do_sb(lst);
				do_rb(lst);
				do_sb(lst);
				do_rrb(lst);
			}
		}
		else
		{
			if (first > second)
			{
				do_rb(lst);
				do_sb(lst);
				do_rrb(lst);
				do_sb(lst);
			}
			else
			{
				do_sb(lst);
				do_rb(lst);
				do_sb(lst);
				do_rrb(lst);
				do_sb(lst);
			}
		}
	}
}
