#ifndef FDF_H
# define FDF_H

/* ---dependencies--- */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "../minilibx_mms_20210621/mlx.h"

# include "get_next_line.h"

/* ---err_msg--- */
# define ERR_ARGC "Usage : ./fdf <filename>"
# define ERR_OPEN "No file "
# define ERR_CLOSE "Close error"
# define ERR_LINE "Found wrong line length. Exiting."
# define ERR_MAP "Map allocate fail. Exiting."
# define ERR_FILE "File is not fdf file"
# define ERR_MLX "MLX initializing failed"

typedef struct s_map
{
	char	*name;
	int		fd;
	int		col;
	int		row;
	int		**z;
	int		**color;
}	t_map;

typedef struct s_mlx
{
	int		win_col;
	int		win_row;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

void	ft_open(char *file_name, int *fd);
void	ft_close(int fd);
size_t	ft_count_str(char const *s, char c);
char	**ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_get_line(int fd, char **backup, char *buffer);
size_t	ft_find_nl_idx(char *backup_fd);
char	*ft_seperate(int fd, char **backup);
char	*ft_eof(int fd, char **backup);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

int		ft_atoi(const char *str);
int		ft_atoi_hex(const char *str);

void	init(t_map *map, t_mlx *mlx, char *argv[]);
void	init_map(t_map *map, char *argv[]);
void	init_mlx(t_mlx *mlx, t_map *map);
void	measure_map(t_map *map);
void	parse_map(t_map *map);
void	msg_error_no(char *msg, int no);

void	print_map(t_map *map);
#endif
