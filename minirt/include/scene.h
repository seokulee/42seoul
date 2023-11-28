#ifndef SCENE_H
# define SCENE_H

# include "struct.h"
# include "math_vec.h"

t_camera	camera(t_canvas *canvas, t_vec3 origin);
t_canvas	canvas(int width, int height);
t_object	*object(t_object_type type, void *component, t_color3 albedo);
t_sphere	*sphere(t_coord3 center, double radius);
t_light		*light_point(t_coord3 orig, t_color3 light_color, double intensity);

#endif
