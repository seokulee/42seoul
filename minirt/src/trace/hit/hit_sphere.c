#include "structure.h"
#include "math_vec.h"
#include "trace.h"

t_bool	hit_sphere(t_object *object, t_ray *ray, t_hit_record *rec)
{
	t_vec3  oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double  a;
	double  half_b;
	double  c;
	double  discriminant; //판별식
	double	sqrtd;
	double	root;
	t_sphere	*sphere;

	sphere = object->component;
	oc = vec_sub(ray->orig, sphere->center);
	// a = vec_dot(ray->dir, ray->dir);
	// b = 2.0 * vec_dot(oc, ray->dir);
	// c = vec_dot(oc, oc) - pow(sphere->radius, 2);
	// // discriminant 는 판별식
	// discriminant = b * b - 4 * a * c;
	a = pow(vec_len(ray->dir), 2);
	half_b = vec_dot(oc, ray->dir);
	c = pow(vec_len(oc), 2) - pow(sphere->radius, 2);
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	rec->t = root;
	rec->coord = ray_at(ray, rec->t);
	rec->normal = vec_div(vec_sub(rec->coord, sphere->center), sphere->radius);
	set_face_normal(ray, rec);
	rec->albedo = object->albedo;
	return (1);
}
