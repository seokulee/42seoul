#include "pipex.h"

void	ft_pipe(t_pack *pack, int level)
{
	if (pipe(pack->pipe_fd[level]) < 0)
		error_msg_no(ERR_PIPE);
}

void	ft_fork(t_pack *pack, int level)
{
	pack->pid[level] = fork();
	if (pack->pid[level] < 0)
		error_msg_no(ERR_FORK);
}

void	ft_dup2(int	from_fd, int to_fd)
{
	if (dup2(from_fd, to_fd) < 0)
		error_msg_no(ERR_DUP2);
}

void	ft_connect_fd(t_pack *pack)
{
	if (pack->cmd_seq == 0)
	{
		ft_close(pack->pipe_fd[pack->cmd_seq][0]);
		ft_dup2(pack->input_file, 0);
		ft_dup2(pack->pipe_fd[pack->cmd_seq][1], 1);
	}
	else if (pack->cmd_seq == pack->n_cmd - 1)
	{
		ft_dup2(pack->pipe_fd[pack->cmd_seq - 1][0], 0);
		ft_dup2(pack->output_file, 1);
		ft_close(pack->pipe_fd[pack->cmd_seq][0]);
		ft_close(pack->pipe_fd[pack->cmd_seq][1]);
		ft_close(pack->pipe_fd[pack->cmd_seq - 1][1]);
		ft_close_pipes(pack, pack->cmd_seq - 1);
	}
	else
	{
		ft_dup2(pack->pipe_fd[pack->cmd_seq - 1][0], 0);
		ft_dup2(pack->pipe_fd[pack->cmd_seq][1], 1);
		ft_close(pack->pipe_fd[pack->cmd_seq - 1][1]);
		ft_close(pack->pipe_fd[pack->cmd_seq][0]);
		ft_close_pipes(pack, pack->cmd_seq - 1);
	}
}

void	ft_execve(t_pack *pack)
{
	char	*cmd;
	char	**cmd_tab;

	ft_connect_fd(pack);
	cmd_tab = ft_split(pack->argv[pack->cmd_seq + 2], ' ');
	cmd = get_cmd(pack->path_tab, cmd_tab[0]);
	if (!cmd)
		error_msg_no(ERR_CMD);
	if (execve(cmd, cmd_tab, pack->envp) < 0)
		error_msg_no(ERR_EXECVE);
}

void	ft_execve_hd(t_pack *pack)
{
	char	*cmd;
	char	**cmd_tab;

	ft_connect_fd(pack);
	cmd_tab = ft_split(pack->argv[pack->cmd_seq + 3], ' ');
	cmd = get_cmd(pack->path_tab, cmd_tab[0]);
	if (!cmd)
		error_msg_no(ERR_CMD);
	if (execve(cmd, cmd_tab, pack->envp) < 0)
		error_msg_no(ERR_EXECVE);
}

void	ft_open(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		error_msg_no(ERR_OPEN);
}

void	ft_output_file(char *file_name, int *fd)
{
		*fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (*fd < 0)
			error_msg_no(ERR_OUTPUT);
}

void	ft_output_file_hd(char *file_name, int *fd)
{
		*fd = open(file_name, O_CREAT | O_APPEND | O_RDWR, 0644);
		if (*fd < 0)
			error_msg_no(ERR_OUTPUT);
}

void	ft_close_pipes(t_pack *pack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_close(pack->pipe_fd[i][0]);
		ft_close(pack->pipe_fd[i][1]);
		i++;
	}
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		error_msg_no(ERR_CLOSE);
}

void	ft_wait_child(t_pack *pack, int level)
{
	int	i;

	i = 0;
	while (i++ < level)
		ft_wait();
	waitpid(pack->pid[level], &pack->status, 0);
}

void	ft_wait()
{
	if (wait(NULL) < 0)
		error_msg_no(ERR_WAIT);
}
