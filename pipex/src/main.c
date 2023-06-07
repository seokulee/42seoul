#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		return (error_msg(ERR_ARGC));
	(void)argv, (void) envp;
}
