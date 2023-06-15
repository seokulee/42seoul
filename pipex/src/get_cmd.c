#include "pipex.h"

char	*get_cmd(char **path_tab, char *only_cmd)
{
	char	*tmp;
	char	*cmd;

	if (!only_cmd)
		return (NULL);
	while (*path_tab)
	{
		tmp = ft_strjoin(*path_tab, "/");
		cmd = ft_strjoin(tmp, only_cmd);
		free(tmp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		path_tab++;
	}
	return (NULL);
}
