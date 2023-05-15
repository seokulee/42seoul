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
		//b = lst_new();
		if (!data_preprocessing(argc, argv, a))
		{
			lst_clear(a);
			printf("error\n");
			return (-1);
		}
		lst_print(a);
		ft_printf("TOP:		%d\n", a->head->value);
		ft_printf("BOT:		%d\n", a->tail->value);
		ft_printf("CNT:		%d\n", a->count);

		quicksort(a->head, a->tail);
		lst_print(a);
	}
}