#include "pipex.h"

void	child_one_proc(t_package *pack, char *argv[], char *envp[])
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY);
	if (input_file < 0)
	{
		error_msg_errno(ERR_INPUT);
		exit(1);
	}
	dup2(pack->pipe_fd[1], 1);
	close(pack->pipe_fd[0]);
	dup2(input_file, 0);
	pack->cmd_tab = ft_split(argv[2], ' ');
	pack->cmd = get_cmd(pack->path_tab, pack->cmd_tab[0]);
	if (!pack->cmd)
	{
		error_msg(ERR_CMD);
		exit(1);
	}
	execve(pack->cmd, pack->cmd_tab, envp);
}
