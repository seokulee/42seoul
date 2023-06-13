#include "pipex.h"

void	child_two_proc(t_package *pack, char *argv[], char *envp[])
{
	int	output_file;

	output_file = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (output_file < 0)
	{
		error_msg_errno(ERR_OUTPUT);
		exit(1);
	}
	dup2(pack->pipe_fd[0], 0);
	close(pack->pipe_fd[1]);
	dup2(output_file, 1);
	pack->cmd_tab = ft_split(argv[3], ' ');
	pack->cmd = get_cmd(pack->path_tab, pack->cmd_tab[0]);
	if (!pack->cmd)
	{
		error_msg(ERR_CMD);
		exit(127);
	}
	execve(pack->cmd, pack->cmd_tab, envp);
}
