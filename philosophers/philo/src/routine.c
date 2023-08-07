/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:23:18 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/07 09:48:22 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eat(t_args *args, t_philo *philo);
void	eating(t_args *args);
void	sleeping(t_args *args, t_philo *philo);

void	*routine(void *param)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)param;
	args = philo->args;
	if (philo->id % 2)
		usleep(10 * 1000);
	while (!args->die)
	{
		print_status("%lld %d is thinking\n", philo->id, args);
		if (eat(args, philo))
			break ;
		sleeping(args, philo);
	}
	return (0);
}

int	eat(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(&args->forks[philo->id]);
	print_status("%lld %d has taken a fork\n", philo->id, args);
	if (philo->id == right_of(philo))
		return (1);
	pthread_mutex_lock(&args->forks[right_of(philo)]);
	print_status("%lld %d has taken a fork\n", philo->id, args);
	pthread_mutex_lock(&args->mutex_eat);
	print_status("%lld %d is eating\n", philo->id, args);
	philo->last_eat = get_current_time();
	philo->cnt_eat++;
	pthread_mutex_unlock(&args->mutex_eat);
	eating(args);
	pthread_mutex_unlock(&args->forks[right_of(philo)]);
	pthread_mutex_unlock(&args->forks[philo->id]);
	pthread_mutex_lock(&args->mutex_eat);
	if (args->done_eat)
	{
		pthread_mutex_unlock(&args->mutex_eat);
		return (1);
	}
	pthread_mutex_unlock(&args->mutex_eat);
	return (0);
}

void	sleeping(t_args *args, t_philo *philo)
{
	long long	time_start_sleeping;

	print_status("%lld %d is sleeping\n", philo->id, args);
	time_start_sleeping = get_current_time();
	while (1)
	{
		pthread_mutex_lock(&args->mutex_eat);
		if (args->die)
		{
			pthread_mutex_unlock(&args->mutex_eat);
			break ;
		}
		pthread_mutex_unlock(&args->mutex_eat);
		if (get_current_time() - time_start_sleeping >= args->time_to_sleep)
			break ;
		usleep(800);
	}
}

void	eating(t_args *args)
{
	long long	time_start_eating;

	time_start_eating = get_current_time();
	while (1)
	{
		pthread_mutex_lock(&args->mutex_eat);
		if (args->die)
		{
			pthread_mutex_unlock(&args->mutex_eat);
			break ;
		}
		pthread_mutex_unlock(&args->mutex_eat);
		if (get_current_time() - time_start_eating >= args->time_to_eat)
			break ;
		usleep(800);
	}
}
