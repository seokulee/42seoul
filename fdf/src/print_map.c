#include "fdf.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	printf("ord : %d abs : %d\n", map->row, map->col);
	while (i < map->row)
	{
		j = 0;
		printf("%d  ",i);
		while (j < map->col)
		{
			printf("%d ",map->z[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	i = 0;
	while (i < map->row)
	{
		j = 0;
		printf("%d  ",i);
		while (j < map->col)
		{
			printf("%d ",map->color[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
