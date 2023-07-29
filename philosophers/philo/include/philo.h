#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define LONG_DET 922337203685477580L
# define LONG_MAX 9223372036854775807L

# define ERR_ARGC "./philo num_philo t_die t_eat t_sleep [num_must eat]\n"
# define ERR_ARGS "Can't run with this arguments\n"
# define ERR_ROUTINE "Routine Failed\n"

typedef struct s_philo t_philo;

typedef struct s_args
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				done_eat;
	long long		start_time;
	int				die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t mutex_print;
	t_philo			*philos;
}	t_args;

typedef	struct s_philo
{
	int			id;
	pthread_t	tid;
	long long	last_eat;
	int			cnt_eat;
	t_args		*args;
}	t_philo;

/* ft_atoi.c */
int	ft_atoi(const char *str);
int	init(t_args *args, int argc, char *argv[]);
int	start_routine(t_args *args, t_philo *philos);

/* routine.c */
void	*routine(void *param);

/* utils.c */
long long	get_current_time(void);
int		left_of(t_philo *philo);
int		right_of(t_philo *philo);
void	print_status(const char *s, int id, t_args *args);

#endif
