#include "push_swap.h"

void	data_preprocessing(int argc, char **argv)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!space_null_char(argv[i][j]))
			{
				
			}
		}
	}
}
static int	space_null_char(int c)
{
	if ((c >= 10 && c <=13) || c == 32 || c == 0)
		return (1);
	return (0);
}