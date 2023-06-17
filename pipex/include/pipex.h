#ifndef PIPEX_H
# define PIPEX_H

/* ---dependencies--- */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

/* ---error msg--- */
# define ERR_ARGC "Numbers of Arguments are not available"
# define ERR_PIPE "Pipe error!"
# define ERR_FORK "Fork error!"
# define ERR_CLOSE "Close error!"
# define ERR_OPEN "Open error!"
# define ERR_OUTPUT "Output file error!"
# define ERR_DUP2 "Dup2 error!"
# define ERR_EXECVE "Execve error!"
# define ERR_CMD "Cannot found command"
# define ERR_WAIT "Wait error!"

# define ORDINARY 0
# define HERE_DOC 1

typedef struct s_pack
{
	char	**cmd_tab;
	char	*cmd;
	char	**path_tab;
	char	*path;
	pid_t	first;
	pid_t	last;
	int		pipe_fd[2];
}	t_pack;

void	ft_pipe(int	fd[2]);
void	ft_fork(pid_t *p);
void	ft_open(char *file_name, int *fd);
void	ft_open_outfile(char *file_name, int option, int *fd);
void	ft_close(int fd);
void	ft_close_pipe(int fd[2]);
void	ft_dup2(int	from_fd, int to_fd);
void	ft_wait(int i);
void	ft_execve(t_pack *pack, char *cmd, char *envp[]);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**ft_free_tab(char **tab);
char	*sub_quotation(char *s);
int		msg_error(char *msg);
void	msg_error_no(char *msg);
void	child_first(t_pack *pack, char *argv[], char *envp[], int n);
void	child_middle(t_pack *pack, char *argv[], char *envp[], int n);
void	child_last(t_pack *pack, char *argv[], char *envp[], int n);
char	*get_cmd(char **path_tab, char *cmd_uncertain);
char	*get_path(char *envp[]);

#endif