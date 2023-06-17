#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pack	pack;
	int		status;
	int		i;

	i = 2;
	if (argc < 5)
		return (msg_error(ERR_ARGC));
	ft_pipe(pack.pipe_fd);
	pack.path = get_path(envp);
	pack.path_tab = ft_split(pack.path, ':');
	child_first(&pack, argv, envp, 2);
	while (++i < argc -2)
		child_middle(&pack, argv, envp, i);
	child_last(&pack, argv, envp, argc - 2);
	ft_close_pipe(pack.pipe_fd);
	ft_wait(i);
	waitpid(pack.last, &status, 0);
	ft_free_tab(pack.path_tab);
	return (WEXITSTATUS(status));
}


//int	main(int argc, char *argv[], char *envp[])
//{
//	t_pack	pack;
//	int		input_file;
//	int		output_file;
//	int		i;
//	int		status;

//	i = 2;
//	if (argc < 5)
//		return (msg_error(ERR_ARGC));
//	ft_open(argv[1], &input_file);
//	output_file = open(argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
//	if (output_file < 0)
//		exit(msg_error(ERR_OUTPUT));
//	pack.path = get_path(envp);
//	pack.path_tab = ft_split(pack.path, ':');
//	ft_dup2(input_file, 0);
//	ft_dup2(output_file, 1);
//	child_proc(&pack, argv[2], envp, input_file);
//	while (++i < argc - 2)
//		child_proc(&pack, argv[i], envp, 1);
//	ft_execve(&pack, argv[i], envp);
//}

//void	child_proc(t_pack *pack, char *cmd, char *envp[], int input)
//{
//	pid_t	tmp;

//	pipe(pack->pipe_fd);
//	ft_fork(tmp);
//	if (tmp)
//	{
//		ft_close(pack->pipe_fd[1]);
//		ft_dup2(pack->pipe_fd[0], 0);
//		waitpid(tmp, NULL, 0);
//	}
//	else
//	{
//		ft_close(pack->pipe_fd[0]);
//		ft_dup2(pack->pipe_fd[1], 1);
//		if (input == 0)
//			exit(1);
//		else
//			ft_execve(&pack, cmd, envp);
//	}
//}

//void	ft_execve(t_pack *pack, char *cmd, char *envp[])
//{
//	char	*cmd_line;

//	cmd_line = sub_quotation(cmd);
//	pack->cmd_tab = ft_split(cmd_line, ' ');
//	pack->cmd = get_cmd(pack->path_tab, pack->cmd_tab[0]);
//	free(cmd_line);
//	if (!pack->cmd)
//		exit(msg_error(ERR_CMD) + 126);
//	if (execve(pack->cmd, pack->cmd_tab, envp) < 0)
//		msg_error_no(ERR_EXECVE);
//}
