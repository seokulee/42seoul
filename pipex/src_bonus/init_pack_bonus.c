#include "pipex.h"

void	init_pack(t_pack *pack, int argc, char *argv[], char *envp[])
{
	pack->argv = argv;
	pack->envp = envp;
	pack->path_tab = ft_split(get_path(envp), ':');
	pack->cmd_seq = 0;
	pack->status = 0;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		pack->n_cmd = argc - 4;
		pack->escape = ft_strjoin(argv[2], "\n");
		pack->input_file = open("hd_rd", O_CREAT | O_APPEND | O_RDWR, 0644);
		if (pack->input_file < 0)
			error_msg_no(ERR_OUTPUT);
		ft_output_file_hd(pack->argv[pack->n_cmd + 3], &pack->output_file);
		pack->here_doc = 1;
	}
	else
	{
		pack->n_cmd = argc - 3;
		ft_open(pack->argv[1], &pack->input_file);
		ft_output_file(pack->argv[pack->n_cmd + 2], &pack->output_file);
		pack->here_doc = 0;
	}
}
