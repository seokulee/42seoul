#include "push_swap.h"

static int	ft_n_len(int n);
static int	ft_abs(int n);

char	*ps_itoa(int n)
{
	int		n_len;
	int		sign;
	char	*arr;

	sign = 1;
	if (n < 0)
		sign = -1;
	n_len = ft_n_len(n);
	arr = (char *)malloc(sizeof(char) * n_len + 1);
	if (!arr)
		return (NULL);
	arr += n_len;
	*arr = '\0';
	while (n_len--)
	{
		*--arr = (char)(ft_abs(n % 10) + '0');
		n /= 10;
	}
	if (sign == -1)
		*arr = '-';
	return (arr);
}

static int	ft_n_len(int n)
{
	int	n_len;

	n_len = 0;
	if (n <= 0)
		n_len = 1;
	else
		n_len = 0;
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
