#ifndef TRACE_H
# define TRACE_H

# include "struct.h"
# include "math_vec.h"

t_ray		ray(t_coord3 orig, t_vec3 dir);
t_coord3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *camera, double u, double v);
// t_color3	ray_color(t_ray *ray, t_color3 *background);
t_color3	ray_color(t_scene *scene);

t_bool		hit(t_object *object, t_ray *ray, t_hit_record *rec);
t_bool		hit_object(t_object *object, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_object *object, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);

t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);

t_bool		in_shadow(t_object *world, t_ray light_ray, double light_len);


#endif
