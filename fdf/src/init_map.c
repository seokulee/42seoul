#include "fdf.h"

void	init_map(t_map *map, char *argv[])
{
	map->name = argv[1];
	ft_open(map->name, &map->fd);
	if (ft_strncmp(&map->name[ft_strlen(map->name) - 3], "fdf", 4))
		msg_error_no(ERR_FILE, 1);
	map->abscissa = 0;
	map->ordinate = 0;
	map->altitude = 0;
}
