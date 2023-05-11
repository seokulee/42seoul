#include "push_swap.h"

int	data_preprocessing(int argc, char **argv, t_list *a)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (check_dup(a, ft_atoi(argv[i])) > 0)
			lst_add_tail(a, node_new(ft_atoi(argv[i])));
		else
			return (-1);
	}
	return (1);
}