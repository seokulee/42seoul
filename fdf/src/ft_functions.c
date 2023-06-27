#include "fdf.h"

void	ft_open(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		msg_error_no(ERR_OPEN, errno);
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		msg_error_no(ERR_CLOSE, errno);
}
