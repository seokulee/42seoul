#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	left_of(t_philo *philo)
{
	return ((philo->id + philo->args->num_philos - 1) % philo->args->num_philos);
}

int	right_of(t_philo *philo)
{
	return ((philo->id + 1) % philo->args->num_philos);
}

void	print_status(const char *s, int id, t_args *args)
{
	pthread_mutex_lock(&args->mutex_print);
	if (!args->die)
		printf(s, get_current_time() - args->start_time, id + 1);
	pthread_mutex_unlock(&args->mutex_print);
}
