#include "pipex.h"

void	second_child_proc(t_pipe *pipex, char *argv[], char *envp[])
{
	dup2(pipex->fd[0], 0);
	close(pipex->fd[1]);
	dup2(pipex->output, 1);
	pipex->cmd_args = ft_split(argv[3], ' ');
	pipex->cmd = get_cmd(pipex->path_tab, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		error_msg(ERR_CMD);
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}