#include "scene.h"

t_object	*object(t_object_type type, void *component, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->component = component;
	new->albedo = albedo;
	new->next = NULL;
	return (new);
}

t_sphere	*sphere(t_coord3 center, double radius)
{
	t_sphere *sp;

	if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	return (sp);
}

t_light	*light_point(t_coord3 orig, t_color3 light_color, double intensity)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->orig = orig;
	light->light_color = light_color;
	light->intensity = intensity;
	return (light);
}
