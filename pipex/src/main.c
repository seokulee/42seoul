#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipex;

	pipex = (t_pipe *)malloc(sizeof(t_pipe));
	if (!pipex)
		return (NULL);
	if (argc != 5)
		return (error_msg(ERR_ARGC));
	if ((pipex->input = open(argv[1], O_RDONLY)) < 0)
		return (error_msg(ERR_INPUT));
	if ((pipex->output = open(argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0000644)) < 0)
		return (error_msg(ERR_OUTPUT));
	if (pipe(pipex->fd) < 0)
		return (error_msg(ERR_PIPE));
	pipex->path = get_path(envp);
	pipex->path_tab = ft_split(pipex->path, ':');
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first_child_proc(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		second_child_proc(pipex, argv, envp);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	return (0);
}
