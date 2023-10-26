#include "minirt.h"

static int	control_identifier(t_scene *scene, char *id);
static int	count_components(t_scene *scene, char *open_file);
static int	check_components(t_scene *scene);
static int	get_components(t_scene *scene, char *open_file);

int	read_rt_file(t_scene *scene, char *open_file)
{
	if (open_file == NULL || scene == NULL)
		return (-1);
	if (ft_strncmp(open_file + ft_strlen(open_file) - 3, ".rt", 3) != 0)
		return (-1);
	if (count_components(scene, open_file) == -1)
		return (-1);
	if (check_components(scene) == -1)
		return (-1);
	/* 실패 시 components malloc -> free*/
	if (get_components(scene, open_file) == -1)
		return (-1);
	return (1);
}

static int	control_identifier(t_scene *scene, char *id)
{
	if (!ft_strcmp(id, "A"))
		scene->cnt_ambient++;
	else if (!ft_strcmp(id, "C"))
		scene->cnt_camera++;
	else if (!ft_strcmp(id, "L"))
		scene->cnt_lights++;
	else if (!ft_strcmp(id, "sp") || !ft_strcmp(id, "pl") || \
			!ft_strcmp(id, "cy"))
		scene->cnt_objects++;
	else
		return (-1);
	return (1);
}

/* check type identifier and count each of it */
static int	count_components(t_scene *scene, char *open_file)
{
	int		fd;
	char	*line;
	char	**tab;

	if (ft_open(&fd, open_file) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		if (control_identifier(scene, tab[0]) == -1)
		{
			ft_free_tab(tab);
			free(line);
			return (-1);
		}
		ft_free_tab(tab);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_close(fd));
}

/* check if the informations are appropriate values */
static int	check_components(t_scene *scene)
{
	if (scene->cnt_ambient != 1)
		return (-1);
	if (scene->cnt_camera != 1)
		return (-1);
	if (scene->cnt_lights < 1)
		return (-1);
	if (scene->cnt_objects < 1)
		return (-1);
	scene->lights = malloc(sizeof(t_light *) * (scene->cnt_lights + 1));
	if (scene->lights == NULL)
		return (-1);
	ft_memset(scene->lights, 0, sizeof(t_light *) * (scene->cnt_lights + 1));
	scene->objects = malloc(sizeof(t_object *) * (scene->cnt_objects + 1));
	if (scene->objects == NULL)
	{
		free(scene->lights);
		return (-1);
	}
	ft_memset(scene->objects, 0, sizeof(t_object *) * (scene->cnt_objects + 1));
	return (1);
}

static int	get_components(t_scene *scene, char *open_file)
{
	int		fd;
	char	*line;
	char	**tab;

	if (ft_open(&fd, open_file) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		if (!ft_strcmp(tab[0], "A"))
			get_ambient(scene, tab);
		else if (!ft_strcmp(tab[0], "C"))
			get_camera(scene, tab);
		else if (!ft_strcmp(tab[0], "L"))
			get_light(scene, tab);
		else
			get_object(scene, tab);
		ft_free_tab(tab);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_close(fd));
}
