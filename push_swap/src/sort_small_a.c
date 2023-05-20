#include "push_swap.h"

void	sort_small_a(t_list *lst, int cnt)
{
	int	first;
	int	second;
	int	third;

	first = lst->head->value;
	second = lst->head->next->value;
	third = lst->head->next->next->value;
	if (cnt <= 1)
		return ;
	else if (cnt == 2)
	{
		if (first > second)
			do_sa(lst);
		return ;
	}
	else
	{
		if (first > second && first > third)
		{
			if (second > third)
			{
				do_sa(lst);
				do_rra(lst);
			}
			else
				do_ra(lst);
		}
		else if (second > first && second > third)
		{
			if (first > third)
				do_rra(lst);
			else
			{
				do_rra(lst);
				do_sa(lst);
			}
		}
		else
		{
			if (first > second)
				do_sa(lst);
		}
	}
}
