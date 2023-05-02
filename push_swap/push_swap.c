#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	//t_list	*b;

	if (argc < 2)
		return (0);
	else
	{
		a = lst_new();
		if (data_preprocessing(argc, argv, a) < 0)
		{
			//lst_clear(a);
			return (-1);
		}
		lst_print(a);
	}
}