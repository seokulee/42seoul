#include "fdf.h"

void	measure_map(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	map->abscissa = ft_count_str(line, ' ');
	while (line)
	{
		if ((int)ft_count_str(line, ' ') != map->abscissa)
			msg_error_no(ERR_LINE, 1);
		map->ordinate++;
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	ft_close(map->fd);
	ft_open(map->name, &map->fd);
}
