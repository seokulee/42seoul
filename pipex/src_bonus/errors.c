#include "pipex.h"

int	msg_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

void	msg_error_no(char *msg)
{
	perror(msg);
	exit(1);
}
