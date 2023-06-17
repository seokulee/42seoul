#include "pipex.h"

char	*get_path(char *envp[])
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}
