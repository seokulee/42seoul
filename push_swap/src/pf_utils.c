#include "push_swap.h"

static int	ft_n_len(int n);

int	print_char(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	print_nbr(int n)
{
	char	*s;

	s = ps_itoa(n);
	if (!s)
		return (-1);
	if (write(1, s, ft_n_len(n)) < 0)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (ft_n_len(n));
}
int	print_str(char *s)
{
	int	s_len;

	if (!s)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		s_len = 6;
	}
	else
	{
		s_len = ft_strlen(s);
		if (write(1, s, s_len) < 0)
			return (-1);
	}
	return (s_len);
}

static int	ft_n_len(int n)
{
	int	n_len;

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