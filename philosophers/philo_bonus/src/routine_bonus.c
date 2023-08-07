/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:22:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/06 11:36:52 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		routine(t_args *args);
int		eat(t_args *args);
void	*monitor(void *param);
void	main_process(t_args *args, pid_t *pid);

int	start_routine(t_args *args)
{
	pid_t	*pid;
	int		i;

	pid = (pid_t *)malloc(sizeof(pid_t) * args->num_philos);
	if (!pid)
		return (1);
	args->start_time = get_current_time();
	i = 0;
	while (i < args->num_philos)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (1);
		if (pid[i] == 0)
		{
			args->id = i;
			break ;
		}
		i++;
	}
	if (pid[args->id] == 0 && routine(args))
		return (1);
	else
		main_process(args, pid);
	return (0);
}

int	routine(t_args *args)
{
	long long	time_start_sleeping;

	args->last_eat = get_current_time();
	if (pthread_create(&(args->tid), NULL, monitor, args))
		return (1);
	if (args->id % 2)
		usleep(10 * 1000);
	while (1)
	{
		print_status("%lld %d is thinking\n", args);
		if (eat(args))
			return (1);
		if (args->num_must_eat != 0 && args->cnt_eat == args->num_must_eat)
			exit(0);
		print_status("%lld %d is sleeping\n", args);
		time_start_sleeping = get_current_time();
		while (1)
		{
			if (get_current_time() - time_start_sleeping >= args->time_to_sleep)
				break ;
			usleep(800);
		}
	}
	return (0);
}

int	eat(t_args *args)
{
	sem_wait(args->fork);
	print_status("%lld %d has taken a fork\n", args);
	sem_wait(args->fork);
	if (args->num_philos == 1)
		return (1);
	print_status("%lld %d has taken a fork\n", args);
	print_status("%lld %d is eating\n", args);
	args->last_eat = get_current_time();
	args->cnt_eat++;
	while (1)
	{
		if (get_current_time() - args->last_eat >= args->time_to_eat)
			break ;
		usleep(800);
	}
	sem_post(args->fork);
	sem_post(args->fork);
	return (0);
}

void	main_process(t_args *args, pid_t *pid)
{
	int	status;
	int	i;

	i = 0;
	while (i < args->num_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < args->num_philos)
			{
				kill(pid[i], SIGKILL);
				i++;
			}
		}
		i++;
	}
}

void	*monitor(void *param)
{
	t_args		*args;

	args = (t_args *)param;
	while (1)
	{
		sem_wait(args->die);
		if (get_current_time() - args->last_eat > args->time_to_die)
		{
			print_status("%lld %d died\n", args);
			exit(1);
		}
		sem_post(args->die);
		usleep(100);
	}
}
