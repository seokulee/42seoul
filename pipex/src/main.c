#include "pipex.h"

void	init_pack(t_package *pack)
{
	pack->path = NULL;
	pack->path_tab = NULL;
	pack->cmd = NULL;
	pack->cmd_tab = NULL;
	pack->pipe_fd[0] = 0;
	pack->pipe_fd[1] = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_package	pack;
	int	status;

	if (argc < 5)
		return (error_msg(ERR_ARGC));
	init_pack(&pack);
	if (pipe(pack.pipe_fd) < 0)
		return (error_msg_errno(ERR_PIPE));
	pack.path = get_path(envp);
	pack.path_tab = ft_split(pack.path, ':');
	pack.pid_1 = fork();
	if (pack.pid_1 == 0)
		child_one_proc(&pack, argv, envp);
	pack.pid_2 = fork();
	if (pack.pid_2 == 0)
		child_two_proc(&pack, argv, envp);
	if (pack.pid_1 == -1 || pack.pid_2 == -1)
		return (error_msg_errno(ERR_FORK));
	close(pack.pipe_fd[0]);
	close(pack.pipe_fd[1]);
	waitpid(pack.pid_1, NULL, 0);
	waitpid(pack.pid_2, &status, 0);
	return (WEXITSTATUS(status));
}
