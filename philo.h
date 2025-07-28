#ifndef PHILO_H
# define PHILO_H

# define NNN 3

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# include "./libft/libft.h"

typedef enum
{
	FORK_TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	p_action;

typedef struct s_philo
{
	int                 id;
	pthread_t           thread;
	int                 meals_eaten;
	int                 time_to_die;
	int                 time_to_eat;
	int                 time_to_sleep;
	int                 must_eat_count;
	long                last_meal_time;
	pthread_mutex_t     *left_fork;
	pthread_mutex_t     *right_fork;
	pthread_mutex_t		*print_mutex;
}	t_philo;

typedef struct s_misc
{
	pthread_mutex_t	*forks;
    pthread_mutex_t	print_mutex;
    int				num_philos;
}	t_misc;

#endif