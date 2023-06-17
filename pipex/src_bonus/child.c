#include "pipex.h"

void	child_first(t_pack *pack, char *argv[], char *envp[], int n)
{
	int	input_file;

	ft_fork(&pack->first);
	if (!pack->first)
	{
		ft_open(argv[1], &input_file);
		ft_dup2(pack->pipe_fd[1], 1);
		ft_close(pack->pipe_fd[0]);
		ft_dup2(input_file, 0);
		ft_execve(pack, argv[n], envp);
	}
}

void	child_middle(t_pack *pack, char *argv[], char *envp[], int n)
{
	pid_t	middle;
	int		middle_fd[2];

	ft_pipe(middle_fd);
	ft_fork(&middle);
	if (!middle)
	{
		if (n % 2 == 1)
		{
			ft_close(middle_fd[0]);
			ft_dup2(pack->pipe_fd[0], 0);
			ft_close(pack->pipe_fd[1]);
			ft_dup2(middle_fd[1], 1);
			ft_execve(pack, argv[n], envp);
		}
		else
		{
			ft_close(middle_fd[1]);
			ft_dup2(middle_fd[0], 0);
			ft_close(pack->pipe_fd[0]);
			ft_dup2(pack->pipe_fd[1], 1);
			ft_execve(pack, argv[n], envp);
		}
	}
}

void	child_last(t_pack *pack, char *argv[], char *envp[], int n)
{
	int	output_file;

	ft_fork(&pack->last);
	if (!pack->last)
	{
		ft_open_outfile(argv[n + 1], ORDINARY, &output_file);
		ft_dup2(pack->pipe_fd[0], 0);
		ft_close(pack->pipe_fd[1]);
		ft_dup2(output_file, 1);
		ft_execve(pack, argv[n], envp);
	}
}
