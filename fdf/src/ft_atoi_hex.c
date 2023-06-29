#include "fdf.h"

int	ft_atoi_hex(const char *str)
{
	int	ret;
	int	len;
	int	i;

	ret = 0;
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		len--;
	i = len;
	while (--i >= 2)
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret += (str[i] - '0') * (int)pow(16, len - i - 1);
		else if (str[i] >= 'a' && str[i] <= 'f')
			ret += (str[i] - 'a' + 10) * (int)pow(16, len - i - 1);
		else if (str[i] >= 'A' && str[i] <= 'F')
			ret += (str[i] - 'A' + 10) * (int)pow(16, len - i - 1);
	}
	return (ret);
}
