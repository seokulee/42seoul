#include "fdf.h"

int	ft_atoi_hex(const char *str)
{
	int		ret;

	ret = 0;
	str += 2;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			ret += (*str - '0') * 16;
		else if (*str >= 'a' && *str <= 'f')
			ret += (*str - 'a' + 10) * 16;
		str++;
	}
	return (ret);
}
