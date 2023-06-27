#include "fdf.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	printf("ord : %d abs : %d\n", map->ordinate, map->abscissa);
	printf("---  0   1   2   3   4   5   6   7   8   9  10 ---\n");
	while (i < map->ordinate)
	{
		j = 0;
		printf("%d  ",i);
		while (j < map->abscissa)
		{
			printf("%d ",map->color[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
