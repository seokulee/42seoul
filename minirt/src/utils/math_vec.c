#include "math_vec.h"

/* 3R Vector Constructor */
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

/* Coordinate in 3R Constructor */
t_coord3	coord3(double x, double y, double z)
{
	t_coord3	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

/* RGB color Constructor*/
t_color3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

/* Set a vector by given values */
void	set_vec3(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

/* Length(Size) of vector */
double	vec_len(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3	vec_add(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}

t_vec3	vec_add_(t_vec3 vec1, double x, double y, double z)
{
	return (vec3(vec1.x + x, vec1.y + y, vec1.z + z));
}

t_vec3	vec_sub(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

t_vec3	vec_sub_(t_vec3 vec1, double x, double y, double z)
{
	return (vec3(vec1.x - x, vec1.y - y, vec1.z - z));
}

t_vec3	vec_scalar_mul(t_vec3 vec, double n)
{
	return (vec3(vec.x * n, vec.y * n, vec.z * n));
}

t_vec3	vec_vec_mul(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z));
}

t_vec3	vec_div(t_vec3 vec, double n)
{
	return (vec3(vec.x / n, vec.y / n, vec.z / n));
}

/* Vector dot product */
double	vec_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

/* Vector cross product */
t_vec3	vec_cross(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(vec1.y * vec2.z - vec1.z * vec2.y,
				vec1.z * vec2.x - vec1.x * vec2.z,
				vec1.x * vec2.y - vec1.y * vec2.x));
}

/* Vector normalization (Get unit vector) */
t_vec3	vec_norm(t_vec3 vec)
{
	double	len;

	len = vec_len(vec);
	/* Zero vector 일 때 return 값 설정 필요! */
	if (len == 0)
		return (vec3(0, 0, 0));
	return (vec_div(vec, len));
}

t_vec3	vec_min(t_vec3 vec1, t_vec3 vec2)
{
	return (vec3(fmin(vec1.x, vec2.x), fmin(vec1.y, vec2.y), fmin(vec1.z, vec2.z)));
}
