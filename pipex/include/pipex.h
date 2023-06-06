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

# define ERR_INPUT "Infile"
# define ERR_OUTPUT "Outfile"
# define ERR_ARGC "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipe
{
	int		input;
	int		output;
	int		fd[2];
	char	*path;
	char	**path_tab;
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_args;
}	t_pipe;

char	*get_path(char *envp[]);
void	first_child_proc(t_pipe *pipex, char *argv[], char *envp[]);
void	second_child_proc(t_pipe *pipex, char *argv[], char *envp[]);
char	*get_cmd(char **path_tab, char *cmd_args);
int		error_msg(char *msg);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

#endif