#include "push_swap.h"

int	data_preprocessing(int argc, char **argv, t_list *a)
{
	int			i;
	int			j;
	int			k;
	long long	num;
	char		*part;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!space_null_char(argv[i][j]))
			{
				k = 0;
				while (!space_null_char(argv[i][j]))
				{
					if (!isdigit(argv[i][j++]))
						return (-1);
					k++;
				}
				part = (char *)malloc(sizeof(char) * (k + 1));
				strlcpy(part, argv[i][j-k], k + 1);
				// part empty error
				num = ps_atoi(part);
				if (num > INT_MAX || num < INT_MIN)
					//num error
				lst_add_tail(a, node_new(num));
			}
		}
	}
	return (1);
}
static int	space_null_char(int c)
{
	if ((c >= 10 && c <= 13) || c == 32 || c == 0)
		return (1);
	return (0);
}