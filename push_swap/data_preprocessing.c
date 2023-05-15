#include "push_swap.h"

static char	**free_tab(char **tab);
static int	is_available(char *s);

int	data_preprocessing(int argc, char **argv, t_list *a)
{
	int		i;
	int		j;
	char	**argvs;

	i = 0;
	while (++i < argc)
	{
		argvs = ft_split(argv[i], ' ');
		if (!*argvs)
			return (0);
		j = 0;
		while (argvs[j])
		{
			if (!is_available(argvs[j]))
				return (0);
			if (check_dup(a, ft_atoi(argvs[j])))
				lst_add_tail(a, node_new(ft_atoi(argvs[j])));
			else
				return (0);
			j++;
		}
		free_tab(argvs);
	}
	return (1);
}

static int	is_available(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}