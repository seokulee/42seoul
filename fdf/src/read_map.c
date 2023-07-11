/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:34 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:11:35 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	measure_map(t_map *map);
static void	parse_map(t_map *map);
static void	fill_altitude(t_map *map, int y, char *line);
static int	ft_atoi_hex(const char *str);

void	read_map(t_map	*map, char *argv[])
{
	map->name = argv[1];
	if (ft_strncmp(&map->name[ft_strlen(map->name) - 3], "fdf", 4))
		terminate(ERR_FILENAME, 1);
	ft_open(map->name, &map->fd);
	map->z_min = 2147483647;
	map->z_max = -2147483648;
	measure_map(map);
	parse_map(map);
	map->is_color = check_map_color(map);
}

static void	measure_map(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	map->x_size = ft_count_str(line, ' ');
	while (line)
	{
		if ((int)ft_count_str(line, ' ') != map->x_size)
			terminate(ERR_LINE, 1);
		map->y_size++;
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	ft_close(map->fd);
	ft_open(map->name, &map->fd);
}

static void	parse_map(t_map *map)
{
	char	*line;
	int		i;

	map->z_arr = (int *)malloc(sizeof(int) * (map->x_size * map->y_size));
	if (!map->z_arr)
		terminate(ERR_MEM, 1);
	map->clr_arr = (int *)malloc(sizeof(int) * (map->x_size * map->y_size));
	if (!map->clr_arr)
		terminate(ERR_MEM, 1);
	line = get_next_line(map->fd);
	i = 0;
	while (i < map->y_size && line)
	{
		fill_altitude(map, i, line);
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	free(line);
	ft_close(map->fd);
}

static void	fill_altitude(t_map *map, int y, char *line)
{
	char	**num_clrs;
	int		i;
	char	**num_clr;

	num_clrs = ft_split(line, ' ');
	i = 0;
	while (num_clrs[i])
	{
		num_clr = ft_split(num_clrs[i], ',');
		if (num_clr[1] == NULL)
			map->clr_arr[y * map->x_size + i] = -1;
		else
			map->clr_arr[y * map->x_size + i] = ft_atoi_hex(num_clr[1]);
		ft_free_tab(num_clr);
		if (ft_atoi(num_clrs[i]) > map->z_max)
			map->z_max = ft_atoi(num_clrs[i]);
		if (ft_atoi(num_clrs[i]) < map->z_min)
			map->z_min = ft_atoi(num_clrs[i]);
		map->z_arr[y * map->x_size + i] = ft_atoi(num_clrs[i]);
		i++;
	}
	ft_free_tab(num_clrs);
}

static int	ft_atoi_hex(const char *str)
{
	int	ret;
	int	len;
	int	i;

	ret = 0;
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		len--;
	i = len;
	while (--i >= 2)
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret += (str[i] - '0') * (int)pow(16, len - i - 1);
		else if (str[i] >= 'a' && str[i] <= 'f')
			ret += (str[i] - 'a' + 10) * (int)pow(16, len - i - 1);
		else if (str[i] >= 'A' && str[i] <= 'F')
			ret += (str[i] - 'A' + 10) * (int)pow(16, len - i - 1);
	}
	return (ret);
}
