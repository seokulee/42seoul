#include "philo.h"

int		eat(t_args *args, t_philo *philo);
void	sleeping(t_args *args, t_philo *philo);

void	*routine(void *param)
{
	t_philo *philo;
	t_args	*args;

	philo = (t_philo *)param;
	args = philo->args;
	if (philo->id % 2)
		usleep(10 * 1000);
	while (!args->die)
	{
		if (eat(args, philo))
			break;
		sleeping(args, philo);
		print_status("%lld %d is thinking\n", philo->id, args);
	}
	return (0);
}

int	eat(t_args *args, t_philo *philo)
{
	long long	time_start_eating;

	pthread_mutex_lock(&args->forks[philo->id]);
	print_status("%lld %d has taken a fork\n", philo->id, args);
	if(philo->id == right_of(philo))
		return (1);
	pthread_mutex_lock(&args->forks[right_of(philo)]);
	print_status("%lld %d has taken a fork\n", philo->id, args);
	pthread_mutex_lock(&args->mutex_eat);
	print_status("%lld %d is eating\n", philo->id, args);
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&args->mutex_eat);
	philo->cnt_eat++;
	time_start_eating = get_current_time();
	while (!args->die)
	{
		if (get_current_time() - time_start_eating >= args->time_to_eat)
			break ;
		usleep(1000);
	}
	pthread_mutex_unlock(&args->forks[right_of(philo)]);
	pthread_mutex_unlock(&args->forks[philo->id]);
	if (args->done_eat)
		return (1);
	return (0);
}

void	sleeping(t_args *args, t_philo *philo)
{
	long long	time_start_sleeping;

	print_status("%lld %d is sleeping\n", philo->id, args);
	time_start_sleeping = get_current_time();
	while (!args->die)
	{
		if (get_current_time() - time_start_sleeping >= args->time_to_sleep)
			break ;
		usleep(1000);
	}
}
