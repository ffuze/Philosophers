/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:30:45 by adegl-in          #+#    #+#             */
/*   Updated: 2025/08/10 20:55:51 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	thinking(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	print_mess(philo, "is thinking\n", philo->table->start, philo->id);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (is_dead(philo) == 1)
		return (1);
	print_mess(philo, "is sleeping\n", philo->table->start, philo->id);
	usleep(philo->table->time_to_sleep * 1000);
	if (thinking(philo) == 1)
		return (1);
	return (0);
}

int	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork);
		if (is_dead(philo) == 1)
			return (pthread_mutex_unlock(philo->fork), 1);
		pthread_mutex_lock(philo->r_fork);
		if (is_dead(philo) == 1)
		{
			pthread_mutex_unlock(philo->fork);
			return (pthread_mutex_unlock(philo->r_fork), 1);
		}
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		if (is_dead(philo) == 1)
			return (pthread_mutex_unlock(philo->r_fork), 1);
		pthread_mutex_lock(philo->fork);
		if (is_dead(philo) == 1)
		{
			pthread_mutex_unlock(philo->r_fork);
			return (pthread_mutex_unlock(philo->fork), 1);
		}
	}
	return (proceed_routine(philo));
}

int	is_one(t_philo *philo)
{
	print_mess(philo, "has taken a fork\n", philo->table->start, philo->id);
	usleep((philo->table->time_to_die + 1) * 1000);
	is_dead(philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep((philo->table->time_to_sleep + (philo->id * 10)) * 1000);
	while (1)
	{
		pthread_mutex_lock(philo->table->simulation);
		if (philo->table->is_finish == 1)
		{
			pthread_mutex_unlock(philo->table->simulation);
			break ;
		}
		pthread_mutex_unlock(philo->table->simulation);
		if (philo->table->n_philo == 1)
		{
			is_one(philo);
			break ;
		}
		else if (eating(philo) == 1)
			break ;
	}
	return (philo);
}
