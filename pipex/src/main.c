#include "pipex.h"

//int	main(int argc, char *argv[], char *envp[])
//{
//	t_pack	pack;
//	int		status;

//	if (argc != 5)
//		return (msg_error(ERR_ARGC));
//	ft_pipe(pack.pipe_fd);
//	pack.path = get_path(envp);
//	pack.path_tab = ft_split(pack.path, ':');
//	ft_fork(&pack.first);
//	if (pack.first == 0)
//		child_first(&pack, argv, envp, 2);
//	ft_fork(&pack.last);
//	if (pack.last == 0)
//		child_last(&pack, argv, envp, argc - 2);
//	ft_close(pack.pipe_fd[0]);
//	ft_close(pack.pipe_fd[1]);
//	wait(NULL);
//	waitpid(pack.last, &status, 0);
//	ft_free_tab(pack.path_tab);
//	return (WEXITSTATUS(status));
//}

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
