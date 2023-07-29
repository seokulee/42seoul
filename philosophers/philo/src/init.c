#include "philo.h"

int	init_mutex(t_args *args);
int	init_philos(t_args *args);

int	init(t_args *args, int argc, char *argv[])
{
	args->num_philos = ft_atoi(argv[1]);
	if (args->num_philos == 0)
		return (1);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->num_must_eat = 0;
	args->start_time = 0;
	args->die = 0;
	if (argc == 6)
	{
		args->num_must_eat = ft_atoi(argv[5]);
		if (args->num_must_eat <= 0)
			return (1);
	}
	if (init_mutex(args))
		return (1);
	if (init_philos(args))
		return (1);
	return (0);
}

int	init_mutex(t_args *args)
{
	int	i;

	if (pthread_mutex_init(&args->mutex_eat, NULL))
		return (1);
	if (pthread_mutex_init(&args->mutex_print, NULL))
		return (1);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->num_philos);
	if (!args->forks)
		return (1);
	i = 0;
	while (i < args->num_philos)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_args *args)
{
	int	i;

	args->philos = malloc(sizeof(t_philo) * args->num_philos);
	if (!args->philos)
		return (1);
	i = 0;
	while (i < args->num_philos)
	{
		args->philos[i].id = i;
		args->philos[i].last_eat = 0;
		args->philos[i].cnt_eat = 0;
		args->philos[i].args = args;
		i++;
	}
	return (0);
}
