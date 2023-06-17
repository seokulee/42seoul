#include "pipex.h"

void	ft_pipe(int	fd[2])
{
	if (pipe(fd) < 0)
		msg_error_no(ERR_PIPE);
}

void	ft_fork(pid_t *p)
{
	*p = fork();
	if (*p < 0)
		msg_error_no(ERR_FORK);
}

void	ft_open(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		msg_error_no(ERR_OPEN);
}

void	ft_open_outfile(char *file_name, int option, int *fd)
{
	if (option == ORDINARY)
	{
		*fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (*fd < 0)
			msg_error_no(ERR_OUTPUT);
	}
	else if (option == HERE_DOC)
	{
		*fd = open(file_name, O_CREAT | O_APPEND | O_RDWR, 0644);
		if (*fd < 0)
			msg_error_no(ERR_OUTPUT);
	}
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		msg_error_no(ERR_CLOSE);
}

void	ft_close_pipe(int fd[2])
{
	ft_close(fd[0]);
	ft_close(fd[1]);
}

void	ft_dup2(int	from_fd, int to_fd)
{
	if (dup2(from_fd, to_fd) < 0)
		msg_error_no(ERR_DUP2);
}

void	ft_wait(int i)
{
	while (i - 2 > 0)
	{
		if (wait(NULL) < 0)
			msg_error_no(ERR_WAIT);
		i--;
	}

}

void	ft_execve(t_pack *pack, char *cmd, char *envp[])
{
	char	*cmd_line;

	cmd_line = sub_quotation(cmd);
	pack->cmd_tab = ft_split(cmd_line, ' ');
	pack->cmd = get_cmd(pack->path_tab, pack->cmd_tab[0]);
	free(cmd_line);
	if (!pack->cmd)
		exit(msg_error(ERR_CMD) + 126);
	if (execve(pack->cmd, pack->cmd_tab, envp) < 0)
		msg_error_no(ERR_EXECVE);
}