#include "push_swap.h"

static char	**free_tab(char **tab);
static int	is_available(char *s);
static int	check_dup(t_list *lst, int input);

int	get_data(int argc, char **argv, t_list *a)
{
	int		i;
	int		j;
	char	**argvs;

	i = 0;
	while (++i < argc)
	{
		argvs = str_split(argv[i], ' ');
		if (!*argvs)
			return (0);
		j = 0;
		while (argvs[j])
		{
			if (!is_available(argvs[j]))
				return (0);
			if (check_dup(a, ps_atoi(argvs[j])))
				list_add_tail(a, node_new(ps_atoi(argvs[j])));
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
		if (s[i] < '0' || s[i] > '9')
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

static int	check_dup(t_list *lst, int input)
{
	t_node	*now;
	int		i;

	if (!lst)
		return (0);
	now = lst->head;
	i = 0;
	while (i++ < lst->count)
	{
		if (input == now->value)
			return (0);
		now = now -> next;
	}
	return (1);
}
