#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# define ERR_ARGC "Usage: ./minirt <scene.rt>"
# define ERR_FILE "Error: Check file extension and type identifier"
# define ERR_INIT "Error: init failed"

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct	s_ambient
{
	double	ratio;
	t_rgb	*rgb;
}	t_ambient;

typedef struct	s_camera
{
	t_vec	*pos;
	t_vec	*dir;
	double	fov;
}	t_camera;

typedef struct	s_light
{
	t_vec	*pos;
	double	ratio;
	t_rgb	*rgb;
}	t_light;

typedef struct	s_object
{
	char	*type;
	t_vec	*pos;
	t_vec	*normal;
	double	diameter;
	double	height;
	t_rgb	*rgb;
}	t_object;

typedef struct	s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		**lights;
	t_object	**objects;
	size_t		cnt_ambient;
	size_t		cnt_cameras;
	size_t		cnt_lights;
	size_t		cnt_objects;
}	t_scene;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
}	t_data;


t_scene	*init_scene(void);
t_data	*init_data(void);

char	**ft_free_tab(char **tab);

int		read_rt_file(t_scene *scene, char *open_file);

void	get_ambient(t_scene *scene, char **tab);
void	get_camera(t_scene *scene, char **tab);
void	get_light(t_scene *scene, char **tab);
void	get_object(t_scene *scene, char **tab);

double	ft_atof(char *str);
t_rgb	*get_rgb(const char *rgb_string);
t_vec	*get_vec(const char *vec_string);

char	*ft_strtok(char *str, char *delim);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_open(int *fd, char *open_file);
int		ft_close(int fd);

int		err_put_str(char *str, int ret);

void	draw(t_data *data, t_scene *scene);

#endif
