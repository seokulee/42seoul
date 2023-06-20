#include "pipex.h"

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}
int	error_msg_no(char *msg)
{
	perror(msg);
	exit(1);
}