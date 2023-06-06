#include "pipex.h"

int	error_msg(char *msg)
{
	write(2, msg, strlen(msg));
	return (1);
}