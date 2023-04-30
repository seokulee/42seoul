#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		return (0);
	else
	{
		a = lst_new();
		i = 0;
		while (++i < argc)
		{
			lst_add_tail(a, node_new(atoi(argv[i])));
		}
		printf("ORIGINAL a : ");
		lst_print(a);
		b = lst_new();
		push(a, b);
		push(a, b);
		push(a, b);
		printf("AFTER PUSH a : ");
		lst_print(a);
		printf("AFTER PUSH b : ");
		lst_print(b);
		rotate(a);
		rotate(b);
		printf("AFTER rotate a : ");
		lst_print(a);
		printf("AFTER rotate b : ");
		lst_print(b);
		reverse_rotate(a);
		reverse_rotate(b);
		printf("AFTER rev rotate a : ");
		lst_print(a);
		printf("AFTER rev rotate b : ");
		lst_print(b);
	}
}