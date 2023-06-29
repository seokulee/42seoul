#include "fdf.h"

void	fill_altitude(t_map *map, int seq, char *line);

void	parse_map(t_map *map)
{
	char	*line;
	int		i;

	measure_map(map);
	map->z = (int **)malloc(sizeof(int *) * (map->row + 1));
	map->color = (int **)malloc(sizeof(int *) * (map->row + 1));
	if (!(map->z && map->color))
		return ;
	line = get_next_line(map->fd);
	i = 0;
	while (i < map->row && line)
	{
		map->z[i] = (int *)malloc(sizeof(int) * (map->col + 1));
		map->color[i] = (int *)malloc(sizeof(int) * (map->col + 1));
		if (!(map->z[i] && map->color[i]))
			return ;
		fill_altitude(map, i, line);
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	free(line);
	map->z[i] = NULL;
	map->color[i] = NULL;
	ft_close(map->fd);
}

void	fill_altitude(t_map *map, int seq, char *line)
{
	char	**nums;
	int		i;
	char	**colors;

	(void) map;
	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		colors = ft_split(nums[i], ',');
		if (colors[1] == NULL)
			map->color[seq][i] = 0xffffff;
		else
			map->color[seq][i] = ft_atoi_hex(colors[1]);
		ft_free_tab(colors);
		map->z[seq][i] = ft_atoi(nums[i]);
		i++;
	}
	ft_free_tab(nums);
}
