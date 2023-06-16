#ifndef PIPEX_H
# define PIPEX_H

/* ---dependencies--- */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

/* ---error msg--- */
# define ERR_ARGC "Need Only 5 Arguments"
# define ERR_PIPE "Pipe error!"
# define ERR_FORK "Fork error!"
# define ERR_CLOSE "Close error!"

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

#endif