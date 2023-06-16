#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pack	pack;

	if (argc != 5)
		return (msg_error(ERR_ARGC));
	ft_pipe(&pack.pipe_fd);
	pack.path = get_path(envp);
	pack.path_tab = ft_split(pack.path, ':');
	ft_fork(&pack.first);
	if (pack.first == 0)
		child_first();
	ft_fork(&pack.last);
	if (pack.last == 0)
		child_last();
	ft_close(pack.pipe_fd[0]);
	ft_close(pack.pipe_fd[1]);
	wait(NULL);
	waitpid
}
