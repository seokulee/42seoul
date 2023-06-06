#include "pipex.h"

char	*get_cmd(char **path_tab, char *cmd_args)
{
	char	*tmp;
	char	*cmd;

	while (*path_tab)
	{
		tmp = ft_strjoin(*path_tab, "/");
		cmd = ft_strjoin(tmp, cmd_args);
		free(tmp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		path_tab++;
	}
	return (NULL);
}
