#ifndef MATH_VEC_H
# define MATH_VEC_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "structure.h"

t_vec3		vec3(double x, double y, double z);
t_coord3	coord3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
void		set_vec3(t_vec3 *vec, double x, double y, double z);
double		vec_len(t_vec3 vec);
t_vec3		vec_add(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_add_(t_vec3 vec1, double x, double y, double z);
t_vec3		vec_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_sub_(t_vec3 vec1, double x, double y, double z);
t_vec3		vec_scalar_mul(t_vec3 vec, double n);
t_vec3		vec_vec_mul(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_div(t_vec3 vec, double n);
double		vec_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec_norm(t_vec3 vec);
t_vec3		vec_min(t_vec3 vec1, t_vec3 vec2);

void		obj_add(t_object **list, t_object *new);
t_object	*obj_last(t_object **list);

#endif
