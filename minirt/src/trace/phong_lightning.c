#include "trace.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*light;

	light_color = color3(0, 0, 0);
	light = scene->light;
	while (light)
	{
		if (light->type == LIGHT_POINT)
			light_color = vec_add(light_color, point_light_get(scene, light->component));
		light = light->next;
	}
	light_color = vec_add(light_color, scene->ambient);
	return (vec_min(vec_vec_mul(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vec_sub(v, vec_scalar_mul(n, 2 * vec_dot(v, n))));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
	t_color3	specular;
	double		light_len;
	t_ray		light_ray;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	double		brightness;

	light_dir = vec_sub(light->orig, scene->rec.coord);
	light_len = vec_len(light_dir);
	light_ray = ray(vec_add(scene->rec.coord, vec_scalar_mul(scene->rec.normal, EPSILON)), light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color3(0, 0, 0));
	light_dir = vec_norm(light_dir);
	kd = fmax(vec_dot(scene->rec.normal, light_dir), 0.0);
	diffuse = vec_scalar_mul(light->light_color, kd);

	view_dir = vec_norm(vec_sub(scene->camera.orig, scene->rec.coord));
	reflect_dir = reflect(vec_scalar_mul(light_dir, -1), scene->rec.normal);
	ksn = 64; // shiniess value
	ks = 0.5; // specular strength
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = vec_scalar_mul(light->light_color, ks * spec);

	brightness = light->intensity * LUMEN;
	return (vec_scalar_mul(vec_add(vec_add(scene->ambient, diffuse), specular), brightness));
}

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}
