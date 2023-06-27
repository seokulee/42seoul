#include "fdf.h"

void	msg_error_no(char *msg, int no)
{
	write(2, msg, ft_strlen(msg));
	exit(no);
}
