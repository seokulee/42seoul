#include "scene.h"

t_camera	camera(t_canvas *canvas, t_coord3 orig)
{
	t_camera	camera;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	camera.orig = orig;
	camera.viewport_h = viewport_height;
	camera.viewport_w = canvas->aspect_ratio * viewport_height;
	camera.horizontal = vec3(focal_len * camera.viewport_w, 0, 0);
	// camera.horizontal = vec3(camera.viewport_w, 0, 0);
	camera.vertical = vec3(0, focal_len * camera.viewport_h, 0);
	// camera.vertical = vec3(0, camera.viewport_h, 0);
	camera.lower_left_corner = vec_sub(vec_sub(vec_sub(camera.orig,
								vec_div(camera.horizontal, 2)),
								vec_div(camera.vertical, 2)),
								vec3(0, 0, focal_len));

	return (camera);
}
