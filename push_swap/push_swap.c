#include "push_swap.h"

#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	int		i;

	if (argc < 2)
		return (0);
	else
	{
		a = lst_new();
		i = 0;
		while (++i < argc)
		{
			lst_add_tail(a, node_add(atoi(argv[i])));
		}
		lst_print(a);
	}
}