#include "pipex.h"

void	exe_cmd_hd(t_pack *pack, int level)
{
	if (level > pack->n_cmd - 1)
		return ;
	pack->cmd_seq = level;
	ft_pipe(pack, level);
	ft_fork(pack, level);
	if (pack->pid[level] == 0)
		ft_execve_hd(pack);
	else if (pack->pid[level] > 0)
	{
		if (level == pack->n_cmd - 1)
		{
			ft_close_pipes(pack, level);
			ft_wait_child(pack, level);
		}
		exe_cmd(pack, level + 1);
	}
}
