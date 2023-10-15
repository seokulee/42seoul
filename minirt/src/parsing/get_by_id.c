#include "minirt.h"

void	get_ambient(t_scene *scene, char **tab)
{
	t_ambient *ambient;

	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (ambient == NULL)
		return ;
	ambient->ratio = ft_atof(tab[1]);
	ambient->rgb = get_rgb(tab[2]);
	scene->ambient = ambient;
}

void	get_camera(t_scene *scene, char **tab)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
		return ;
	camera->pos = get_vec(tab[1]);
	camera->dir = get_vec(tab[2]);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
}

/* get_rgb in get_lights is bonus part */
void	get_light(t_scene *scene, char **tab)
{
	t_light	*light;
	int		idx;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return ;
	light->pos = get_vec(tab[1]);
	light->ratio = ft_atof(tab[2]);
	light->rgb = get_rgb(tab[3]);
	idx = 0;
	while (scene->lights[idx])
		idx++;
	scene->lights[idx] = light;
}

void	get_object(t_scene *scene, char **tab)
{
	t_object	*object;
	int			idx;

	object = (t_object *)malloc(sizeof(t_object));
	if (object == NULL)
		return ;
	idx = 0;
	object->type = ft_strdup(tab[idx++]);
	object->pos = get_vec(tab[idx++]);
	if (ft_strcmp(object->type, "sp") == 0)
		object->diameter = ft_atof(tab[idx++]);
	else if (ft_strcmp(object->type, "pl") == 0)
		object->normal = get_vec(tab[idx++]);
	else if (ft_strcmp(object->type, "cy") == 0)
	{
		object->normal = get_vec(tab[idx++]);
		object->diameter = ft_atof(tab[idx++]);
		object->height = ft_atof(tab[idx++]);
	}
	object->rgb = get_rgb(tab[idx]);
	idx = 0;
	while (scene->objects[idx])
		idx++;
	scene->objects[idx] = object;
}
