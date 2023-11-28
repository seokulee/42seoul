#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_coord3;
typedef struct s_vec3 t_color3;
typedef struct s_ray t_ray;
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;
typedef struct s_scene t_scene;
typedef struct s_object t_object;
typedef struct s_sphere t_sphere;
typedef struct s_light t_light;
typedef struct s_hit_record t_hit_record;

typedef int t_bool;
# define TRUE 1
# define FALSE 0

typedef int t_object_type;
# define SP 0
# define LIGHT_POINT 1

# define EPSILON 1e-6 // 0.000001
# define LUMEN 3

struct s_vec3
{
	double x;
	double y;
	double z;
};

struct s_ray
{
	t_coord3	orig;
	t_vec3		dir;
};

struct s_camera
{
	t_coord3	orig;
	double		viewport_w;
	double		viewport_h;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_coord3	lower_left_corner;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_hit_record
{
	t_coord3	coord;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	int			front_face;
	t_color3	albedo;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

struct s_sphere
{
	t_coord3	center;
	double		radius;
};

struct s_light
{
	t_coord3	orig;
	t_color3	light_color;
	double		intensity; //luminous flux ratio
};

struct s_object
{
	t_object_type	type;
	void			*component;
	t_color3		albedo;
	void			*next;
};


#endif
