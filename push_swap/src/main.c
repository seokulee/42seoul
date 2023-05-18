#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = list_new();
	b = list_new();
	if (!get_data(argc, argv, a))
	{
		list_clear(a);
		list_clear(b);
		ft_printf("Error\n");
	}
	else
	{
		lst_print_tmp(a, b);
	}
	do_sa(a);
	do_rra(a);
	lst_print_tmp(a, b);
	list_clear(a);
	list_clear(b);
}