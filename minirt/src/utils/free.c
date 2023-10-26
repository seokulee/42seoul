#include "minirt.h"

char	**ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_all(t_scene *scene)
{
	size_t	i;

	free(scene->ambient);
	free(scene->camera);
	i = 0;
	while (i < scene->cnt_lights)
	{
		free(scene->lights[i]->pos);
		free(scene->lights[i]->rgb);
		free(scene->lights[i]);
		i++;
	}
	free(scene->lights);
	i = 0;
	while (i < scene->cnt_objects)
	{
		free(scene->objects[i]->pos);
		if (scene->objects[i]->normal)
			free(scene->objects[i]->normal);
		free(scene->objects[i]->rgb);
		free(scene->objects[i]);
		i++;
	}
	free(scene->objects);
	free(scene);
	exit(0);
}
