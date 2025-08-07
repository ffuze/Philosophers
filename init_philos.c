/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:30:36 by adegl-in          #+#    #+#             */
/*   Updated: 2025/08/07 11:52:06 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long	take_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_thread(t_table *table, t_philo **philos)
{
	pthread_t	*thread;
	pthread_t	monitor;
	int			i;

	i = -1;
	pthread_mutex_init(table->printing, NULL);
	pthread_mutex_init(table->simulation, NULL);
	thread = malloc((sizeof(pthread_t) * table->n_philo));
	table->is_finish = 0;
	table->start = take_time();
	while (++i < table->n_philo)
		pthread_create(&thread[i], NULL, routine, philos[i]);
	pthread_create(&monitor, NULL, monitor_routine, philos);
	i = -1;
	while (++i < table->n_philo)
		pthread_join(thread[i], NULL);
	pthread_join(monitor, NULL);
	free_philo(philos);
	free(thread);
}

void	init(t_table *table)
{
	t_philo	**philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * table->n_philo);
	while (++i < table->n_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->id = i + 1;
		philos[i]->n_eating = 0;
		philos[i]->last_eat = 0;
		philos[i]->table = table;
		if (i == 0)
			philos[i]->fork = malloc(sizeof(pthread_mutex_t));
		else
		{
			philos[i]->fork = malloc(sizeof(pthread_mutex_t));
			philos[i]->r_fork = philos[i - 1]->fork;
		}
		pthread_mutex_init(philos[i]->fork, NULL);
	}
	philos[0]->r_fork = philos[i - 1]->fork;
	table->printing = malloc(sizeof(pthread_mutex_t));
	table->simulation = malloc(sizeof(pthread_mutex_t));
	init_thread(table, philos);
}

void	init_argv(t_table *table, char **av)
{
	table->n_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->n_eat = ft_atoi(av[5]);
	else
		table->n_eat = -1;
}

int	take_args(t_table *table, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i] != NULL)
	{
		if (av[i][0] == '\0' || av[i][0] == '0')
			return (0);
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' &&
				av[i][j] != '+')
				return (0);
		}
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			return (printf("Only INT numbers, "), 0);
	}
	init_argv(table, av);
	return (1);
}
