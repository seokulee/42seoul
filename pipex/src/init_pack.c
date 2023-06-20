#include "pipex.h"

void	init_pack(t_pack *pack, int argc, char *argv[], char *envp[])
{
	pack->argv = argv;
	pack->envp = envp;
	pack->path_tab = ft_split(get_path(envp), ':');
	pack->n_cmd = argc - 3;
	pack->cmd_seq = 0;
	pack->status = 0;
	ft_open(pack->argv[1], &pack->input_file);
	ft_output_file(pack->argv[pack->n_cmd + 2], &pack->output_file);
}
