/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:22:32 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/07 09:52:22 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

/* ft_atoi_bonus.c */
int			ft_atoi(const char *str);

/* init_bonus.c */
int			init(t_args *args, int argc, char *argv[]);

/* routine_bonus.c */
int			start_routine(t_args *args);

/* utils_bonus.c */
long long	get_current_time(void);
void		print_status(const char *s, t_args *args);

#endif
