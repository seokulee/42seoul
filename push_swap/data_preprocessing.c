#include "push_swap.h"

static int		space_null_char(int c);
static int		ft_isdigit(int c);
static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
static size_t	ft_strlen(const char *s);

int	data_preprocessing(int argc, char **argv, t_list *a)
{
	int			i;
	int			j;
	int			k;
	long long	num;
	char		*part;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!space_null_char(argv[i][j]))
			{
				k = 0;
				while (!space_null_char(argv[i][j]))
				{
					if (!ft_isdigit(argv[i][j++]))
						return (-1);
					k++;
				}
				part = (char *)malloc(sizeof(char) * (k + 1));
				if (!part)
					return (-1);
				if (k == 0)
				{
					free(part);
					return (-1) ;
				}
				ft_strlcpy(part, &argv[i][j - k], k + 1);
				num = ps_atoi(part);
				if (num > 2147483647 || num < -2147483648)
				{
					free(part);
					return (-1) ;
				}
				lst_add_tail(a, node_new(num));
				free(part);
			}
		}
	}
	return (1);
}

static int	space_null_char(int c)
{
	if ((c >= 10 && c <= 13) || c == 32 || c == 0)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}