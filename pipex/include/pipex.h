#ifndef PIPEX_H
# define PIPEX_H

/*--dependecies--*/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define ERR_ARGC "Not enogh arguments\n"
# define ERR_CMD "Cannot find commands\n"
# define ERR_PIPE "PIPE error!"
# define ERR_FORK "FORK error!"
# define ERR_INPUT "FILE INPUT error!"
# define ERR_OUTPUT "FILE OUTPUT error!"

typedef struct s_package
{
	char	*path;
	char	**path_tab;
	char	*cmd;
	char	**cmd_tab;
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
}	t_package;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);

int		error_msg(char *msg);
int		error_msg_errno(char *msg);
char	*get_path(char *envp[]);
char	*get_cmd(char **path_tab, char *only_cmd);
void	child_one_proc(t_package *pack, char *argv[], char *envp[]);
void	child_two_proc(t_package *pack, char *argv[], char *envp[]);

#endif