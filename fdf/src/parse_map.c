#include "fdf.h"

void	fill_altitude(t_map *map, int seq, char *line);

void	parse_map(t_map *map)
{
	char	*line;
	int		i;

	measure_map(map);
	map->altitude = (int **)malloc(sizeof(int *) * (map->ordinate + 1));
	map->color = (int **)malloc(sizeof(int *) * (map->ordinate + 1));
	if (!(map->altitude && map->color))
		return ;
	line = get_next_line(map->fd);
	i = 0;
	while (i < map->ordinate && line)
	{
		map->altitude[i] = (int *)malloc(sizeof(int) * (map->abscissa + 1));
		map->color[i] = (int *)malloc(sizeof(int) * (map->abscissa + 1));
		if (!(map->altitude[i] && map->color[i]))
			return ;
		fill_altitude(map, i, line);
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	free(line);
	map->altitude[i] = NULL;
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
		if (colors[1])
			map->color[seq][i] = ft_atoi_hex(colors[1]);
		else
			map->color[seq][i] = 0xffffff;
		printf("%d \n", map->color[seq][i]);
		ft_free_tab(colors);
		map->altitude[seq][i] = ft_atoi(nums[i]);
		i++;
	}
	ft_free_tab(nums);
}
