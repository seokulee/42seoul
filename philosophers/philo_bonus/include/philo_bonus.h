/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:22:32 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/06 11:22:33 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define LONG_DET 922337203685477580L
# define LONG_MAX 9223372036854775807L

# define ERR_ARGC "./philo num_philo t_die t_eat t_sleep [num_must eat]\n"
# define ERR_ARGS "Can't run with this arguments\n"

typedef struct s_args
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_must_eat;
	long long	start_time;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*die;
	int			id;
	pthread_t	tid;
	long long	last_eat;
	int			cnt_eat;
}	t_args;

/* ft_atoi.c */
int	ft_atoi(const char *str);

int	init(t_args *args, int argc, char *argv[]);

/* routine.c */
int	start_routine(t_args *args);

/* utils.c */
long long	get_current_time(void);
void		print_status(const char *s, t_args *args);

#endif
