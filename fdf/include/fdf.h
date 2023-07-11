/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:10:19 by seokklee          #+#    #+#             */
/*   Updated: 2023/07/11 15:10:20 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* dependencies */
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define BUFFER_SIZE 1024
# define PI 3.1415926

/* mouse */
# define LEFT_BT 1
# define RIGHT_BT 2
# define WHEEL_BT 3
# define WHEEL_UP 4
# define WHEEL_DW 5

/* keyboard*/
# define ESCAPE 53
# define LEFT_AR 123
# define RIGHT_AR 124
# define UP_AR 126
# define DW_AR 125
# define PLUS 24
# define MINUS 27
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_I 34
# define KEY_P 35

/* color */
# define DEFAULT_CLR 0xffffff
# define HIGHLIGHT_CLR 0xff0000

/* ERR_MSG */
# define ERR_ARGC "Usage : ./fdf <filename>"
# define ERR_FILENAME "File must be .fdf extension"
# define ERR_OPEN "OPEN error"
# define ERR_CLOSE "CLOSE error"
# define ERR_LINE "Map data error:size"
# define ERR_MEM "Malloc Error!"
# define ERR_MLX "MLX Error"
# define ERR_WIN "Win Error"
# define ERR_IMG "IMG Error"
# define ERR_ADDR "ADDR Error"

typedef struct s_spot
{
	int	x;
	int	y;
	int	z;
	int	clr;
}	t_spot;

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL,
	FREE
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	double			alpha;
	double			beta;
	double			gamma;
	int				x_offset;
	int				y_offset;
	int				zoom;
	int				z_zoom;
}	t_camera;

typedef struct s_mouse
{
	int	mb1_pressed;
	int	mb2_pressed;
	int	wheel_pressed;
	int	cur_x;
	int	cur_y;
	int	prev_x;
	int	prev_y;
}	t_mouse;

typedef struct s_map
{
	int		x_size;
	int		y_size;
	int		z_min;
	int		z_max;
	int		*z_arr;
	int		*clr_arr;
	char	*name;
	int		fd;
	int		is_color;
}	t_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			win_width;
	int			win_height;
	int			bpp;
	int			sl;
	int			e;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}	t_fdf;

void	terminate(char *msg, int exit_num);
void	free_all(t_fdf *fdf);

/* init */
t_fdf	*init_fdf(t_map *map);
t_spot	*init_spot(int x, int y, t_fdf *fdf);
void	init_bresenham(t_spot *s, t_spot *f, t_spot *step, t_spot *diff);

/* functions */
void	ft_open(char *file_name, int *fd);
void	ft_close(int fd);
char	**ft_free_tab(char **tab);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_count_str(char const *s, char c);

/* read_map */
void	read_map(t_map	*map, char *argv[]);

/* gnl */
char	*get_next_line(int fd);

/* transform */
t_spot	*transform_coordinates(t_spot *s, t_fdf *fdf);

/* change keyboard */
void	change_offset(int key, t_fdf *fdf);
void	change_altitude(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);
void	change_angle_key(int key, t_fdf *fdf);

/* change mouse */
void	change_zoom(int mouse, t_fdf *fdf);
void	change_angle_mouse(int x, int y, t_fdf *fdf);

/* draw */
void	draw(t_fdf *fdf);

/* rotate */
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *z, int *x, double beta);
void	rotate_z(int *x, int *y, double gamma);

/* color */
int		get_color(t_spot *s, t_spot *f, t_spot cur);
int		check_map_color(t_map *map);
int		lerp(int s, int f, double ratio);
double	get_ratio(int s, int f, int cur);

void	io_cntl(t_fdf *fdf);

#endif