#include "pipex.h"

void	ft_pipe(int	*fd[2])
{
	if (pipe(*fd) < 0)
		msg_error_no(ERR_PIPE);
}

void	ft_fork(pid_t *p)
{
	*p = fork();
	if (*p < 0)
		msg_error_no(ERR_FORK);
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		msg_error_no(ERR_CLOSE);
}
