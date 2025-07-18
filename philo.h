#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "./libft/libft.h"

typedef struct s_philo
{
	int                 id;
	pthread_t           thread;
	int                 meals_eaten;
	pthread_mutex_t     *left_fork;
	pthread_mutex_t     *right_fork;
}	t_philo;


#endif