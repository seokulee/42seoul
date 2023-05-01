#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	else
	{
		a = lst_new();
		data_processing(argc, argv, a);
	}
}