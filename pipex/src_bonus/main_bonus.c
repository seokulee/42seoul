#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pack	pack;

	if (argc < 5)
		return (error_msg(ERR_ARGC));
	init_pack(&pack, argc, argv, envp);
	if (pack.here_doc)
	{
		get_stdin(&pack);
		exe_cmd_hd(&pack, 0);
		unlink("hd_rd");
	}
	else
		exe_cmd(&pack, 0);
	ft_free_tab(pack.path_tab);
	return (WEXITSTATUS(pack.status));
}
