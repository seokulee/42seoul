/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:21:59 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/06 11:22:00 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sem(t_args *args);

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
	if (argc == 6)
	{
		args->num_must_eat = ft_atoi(argv[5]);
		if (args->num_must_eat <= 0)
			return (1);
	}
	if (init_sem(args))
		return (1);
	return (0);
}

int	init_sem(t_args *args)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_die");
	args->fork = sem_open("sem_fork", O_CREAT, 0644, args->num_philos);
	args->print = sem_open("sem_print", O_CREAT, 0644, 1);
	args->die = sem_open("sem_die", O_CREAT, 0644, 1);
	return (0);
}
