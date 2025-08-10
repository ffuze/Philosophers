/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:30:48 by adegl-in          #+#    #+#             */
/*   Updated: 2025/08/10 20:47:53 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	proceed_routine(t_philo *philo)
{
	print_mess(philo, "has taken a fork\n", philo->table->start, philo->id);
	print_mess(philo, "has taken a fork\n", philo->table->start, philo->id);
	print_mess(philo, "is eating\n", philo->table->start, philo->id);
	pthread_mutex_lock(philo->table->simulation);
	philo->last_eat = take_time();
	philo->n_eating++;
	pthread_mutex_unlock(philo->table->simulation);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->r_fork);
	if (sleeping(philo) == 1)
		return (1);
	return (0);
}

void	print_mess(t_philo *philo, char *str, long start, int id)
{
	long	time;

	pthread_mutex_lock(philo->table->printing);
	time = take_time() - start + (philo->n_eating - philo->n_eating);
	printf("%ld %d %s", time, id, str);
	pthread_mutex_unlock(philo->table->printing);
}

int	f_eat(t_philo **philos)
{
	long	finish;
	int		i;

	finish = 0;
	i = -1;
	if (philos[0]->table->n_eat == -1)
		return (0);
	while (++i < philos[0]->table->n_philo)
	{
		pthread_mutex_lock(philos[i]->table->simulation);
		if (philos[i]->n_eating >= philos[0]->table->n_eat)
			finish++;
		pthread_mutex_unlock(philos[i]->table->simulation);
	}
	if (finish == philos[0]->table->n_philo)
	{
		pthread_mutex_lock(philos[0]->table->simulation);
		philos[0]->table->is_finish = 1;
		pthread_mutex_unlock(philos[0]->table->simulation);
		return (1);
	}
	return (0);
}

int	is_dead(t_philo *philos)
{
	long	time;

	pthread_mutex_lock(philos->table->simulation);
	if (philos->table->is_finish == 1)
		return (pthread_mutex_unlock(philos->table->simulation), 1);
	if (philos->last_eat == 0)
		time = take_time() - philos->table->start;
	else
		time = take_time() - philos->last_eat;
	if (time >= philos->table->time_to_die)
	{
		philos->table->is_finish = 1;
		print_mess(philos, "died\n", philos->table->start, philos->id);
		return (pthread_mutex_unlock(philos->table->simulation), 1);
	}
	pthread_mutex_unlock(philos->table->simulation);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	atoi;
	int		min;

	i = 0;
	atoi = 0;
	min = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -min;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = ((atoi * 10) + (str[i] - 48));
		i++;
	}
	return (atoi * min);
}
