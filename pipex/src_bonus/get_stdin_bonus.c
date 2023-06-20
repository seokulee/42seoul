#include "pipex.h"

void	get_stdin(t_pack *pack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, pack->escape, ft_strlen(line)))
			break ;
		write(pack->input_file, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(pack->escape);
	ft_close(pack->input_file);
	ft_open("hd_rd", &pack->input_file);
}
