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

/* color */
# define DEFAULT_CLR 0xffffff

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
	int		z_dividor;
	int		zoom;
	int		x_offset;
	int		y_offset;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		win_width;
	int		win_height;
	int		bpp;
	int		sl;
	int		e;
	t_map	*map;
}	t_fdf;

/* init */
t_fdf	*init_fdf(t_map *map);
void	init_bresenham(t_spot *s, t_spot *f, t_spot *step, t_spot *diff);

/* functions */
void	ft_open(char *file_name, int *fd);
void	ft_close(int fd);
char	**ft_free_tab(char **tab);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_count_str(char const *s, char c);
void	terminate(char *msg, int exit_num);

/* read_map */
void	read_map(t_map	*map, char *argv[]);

/* error */

/* gnl */
char	*get_next_line(int fd);
char	*ft_get_line(int fd, char **backup, char *buffer);
size_t	ft_find_nl_idx(char *backup_fd);
char	*ft_seperate(int fd, char **backup);
char	*ft_eof(int fd, char **backup);

/* transform */
t_spot	*transform_coordinates(t_spot *s, t_fdf *fdf);
t_spot	*new_spot(int x, int y, t_fdf *fdf);
void	change_zoom(int key, t_fdf *fdf);

/* draw */
void	draw(t_fdf *fdf);

/* color */
int	get_color(t_spot *s, t_spot *f, t_spot cur);

/* inout */
int	key_pressed(int key, void *param);

#endif