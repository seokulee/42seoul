#include "pipex.h"

int	error_msg(char *msg)
{
	//printf("%s %s\n", msg, strerror(errno));
	perror(msg);
	return (1);
}

//int	error_msg(char *msg)
//{
//	write(2, msg, ft_strlen(msg));
//	return (1);
//}
