/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:23:20 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/07 09:48:36 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_condition(t_args *args, t_philo *philos);
void	check_all_eat(t_args *args, t_philo *philos);
void	end_routine(t_args *args, t_philo *philos);

int	start_routine(t_args *args, t_philo *philos)
{
	int	i;

	args->start_time = get_current_time();
	i = 0;
	while (i < args->num_philos)
	{
		philos[i].last_eat = get_current_time();
		if (pthread_create(&philos[i].tid, NULL, routine, &philos[i]))
			return (1);
		i++;
	}
	check_condition(args, philos);
	end_routine(args, philos);
	return (0);
}

void	check_condition(t_args *args, t_philo *philos)
{
	int	i;

	while (!args->done_eat)
	{
		i = 0;
		while ((i < args->num_philos) && (!args->die))
		{
			pthread_mutex_lock(&args->mutex_eat);
			if (get_current_time() - philos[i].last_eat > args->time_to_die)
			{
				print_status("%lld %d died\n", philos[i].id, args);
				args->die = 1;
			}
			pthread_mutex_unlock(&args->mutex_eat);
			i++;
			usleep(1000);
		}
		if (args->die)
			break ;
		check_all_eat(args, philos);
	}
}

void	check_all_eat(t_args *args, t_philo *philos)
{
	int	i;
	int	eaten_all;

	i = 0;
	eaten_all = 1;
	if (args->num_must_eat == 0)
		return ;
	while (args->num_must_eat != 0 && i < args->num_philos)
	{
		pthread_mutex_lock(&args->mutex_eat);
		if (philos[i].cnt_eat < args->num_must_eat)
			eaten_all = 0;
		pthread_mutex_unlock(&args->mutex_eat);
		i++;
	}
	pthread_mutex_lock(&args->mutex_eat);
	args->done_eat = eaten_all;
	pthread_mutex_unlock(&args->mutex_eat);
}

void	end_routine(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->num_philos)
		pthread_join(philos[i++].tid, NULL);
	i = 0;
	while (i < args->num_philos)
		pthread_mutex_destroy(&args->forks[i++]);
	pthread_mutex_destroy(&args->mutex_eat);
	pthread_mutex_destroy(&args->mutex_print);
	free(philos);
	free(args->forks);
}
