#include "minirt.h"

double	ft_atof(char *str)
{
	double	res;
	double	decimal;
	int		sign;
	double	divisor;

	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	res = 0.0;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		divisor = 10.0;
		decimal = 0.0;
		while (ft_isdigit(*str))
		{
			decimal += (*str++ - '0') / divisor;
			divisor *= 10;
		}
	}
	return (res + decimal) * sign;
}

t_rgb	*get_rgb(const char *rgb_string)
{
	t_rgb	*rgb;
	char	*token;
	char	*tmp;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (rgb == NULL)
		return (NULL);
	tmp = ft_strdup(rgb_string);
	token = ft_strtok(tmp, ",");
	rgb->r = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	rgb->g = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	rgb->b = ft_atoi(token);
	free(tmp);
	return (rgb);
}

t_vec	*get_vec(const char *vec_string)
{
	t_vec	*vec;
	char	*token;
	char	*tmp;

	vec = (t_vec *)malloc(sizeof(t_vec));
	if (vec == NULL)
		return (NULL);
	tmp = ft_strdup(vec_string);
	token = ft_strtok(tmp, ",");
	vec->x = ft_atof(token);
	token = ft_strtok(NULL, ",");
	vec->y = ft_atof(token);
	token = ft_strtok(NULL, ",");
	vec->z = ft_atof(token);
	free(tmp);
	return (vec);
}
