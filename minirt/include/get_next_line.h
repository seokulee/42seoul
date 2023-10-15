#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_get_line(int fd, char **backup, char *buffer);
size_t	ft_find_nl_idx(char *backup_fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_seperate(int fd, char **backup);
char	*ft_eof(int fd, char **backup);

#endif
