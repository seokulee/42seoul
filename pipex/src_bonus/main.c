#include "pipex.h"

int	main(int argc, char *argv[], int *envp[])
{
	t_package	pack;
	int			status;
	int			i;
	pid_t		pid_tmp;

	if (argc < 5)
		return (error_msg(ERR_ARGC));
	else
	{
		if (pipe(pack.pipe_fd) < 0)
			return (error_msg_errno(ERR_PIPE));
		i = 3;
		pack.pid_1 = fork();
		if (pack.pid_1 == 0)
			child_one_proc(&pack, argv, envp);
		while (i++ < argc - 2)
		{
			pid_tmp = fork();
			if (pid_tmp == 0)
				middle_proc(&pack, argv, envp, i);
		}
		pack.pid_2 = fork();
		if (pack.pid_2 == 0)
			child_two_proc(&pack, argv, envp);
	}
}
