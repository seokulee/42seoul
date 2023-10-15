#include "minirt.h"

int	err_put_str(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	return (ret);
}
