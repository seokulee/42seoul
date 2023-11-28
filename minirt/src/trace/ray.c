#include "trace.h"

/* ray constructor (with normaliztion of direction)*/
t_ray	ray(t_coord3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_norm(dir);
	return (ray);
}

/* ray->orig 에서 ray dir * t 만큼 떨어진 coord */
t_coord3	ray_at(t_ray *ray, double t)
{
	return (vec_add(ray->orig, vec_scalar_mul(ray->dir, t)));
}

t_ray	ray_primary(t_camera *camera, double u, double v)
{
	t_ray	ray;

	ray.orig = camera->orig;
	ray.dir = vec_norm(vec_sub(vec_add(vec_add(camera->lower_left_corner,
	vec_scalar_mul(camera->horizontal, u)),
	vec_scalar_mul(camera->vertical, v)), camera->orig));
	return (ray);
}

t_hit_record	record_init(void)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	return (rec);
}

t_color3	ray_color(t_scene *scene)
{
	double			t;
	t_vec3			normal;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
	{
		t = 0.5 * (scene->ray.dir.y + 1.0);
		return (vec_add(vec_scalar_mul(color3(1.0, 1.0, 1.0), 1.0 - t), vec_scalar_mul(color3(0.5, 0.7, 1.0), t)));
	}
}
