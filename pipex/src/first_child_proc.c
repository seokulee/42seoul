#include "pipex.h"

void	first_child_proc(t_pipe *pipex, char *argv[], char *envp[])
{
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	dup2(pipex->input, 0);
	pipex->cmd_args = ft_split(argv[2], ' ');
	pipex->cmd = get_cmd(pipex->path_tab, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		error_msg(ERR_CMD);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}