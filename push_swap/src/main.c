#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = list_new();
	b = list_new();
	if (!get_data(argc, argv, a))
	{
		//list_clear(a);
		//list_clear(b);
		printf("Error\n");
		exit(0);
	}
	lst_print_tmp(a, b);
	sort(a, b);
	lst_print_tmp(a, b);
	list_clear(a);
	list_clear(b);
}