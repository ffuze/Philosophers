#include "./philo.h"

int	thinking(t_philo *philo)
{
	if (is_dead(philo) == 1 || f_eat(philo) == 1)
		return (1);
	print_mess(philo, "is thinking\n", philo->table->start, philo->id);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (is_dead(philo) == 1 || f_eat(philo) == 1)
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
		if (is_dead(philo) == 1 || f_eat(philo) == 1)
			return (pthread_mutex_unlock(philo->fork), 1);
		pthread_mutex_lock(philo->r_fork);
		if (is_dead(philo) == 1 || f_eat(philo) == 1)
		{
			pthread_mutex_unlock(philo->fork);
			return (pthread_mutex_unlock(philo->r_fork), 1);
		}
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		if (is_dead(philo) == 1 || f_eat(philo) == 1)
			return (pthread_mutex_unlock(philo->r_fork), 1);
		pthread_mutex_lock(philo->fork);
		if (is_dead(philo) == 1 || f_eat(philo) == 1)
		{
			pthread_mutex_unlock(philo->r_fork);
			return (pthread_mutex_unlock(philo->fork), 1);
		}
	}
	print_mess(philo, "has taken a fork\n", philo->table->start, philo->id);
	print_mess(philo, "has taken a fork\n", philo->table->start, philo->id);
	print_mess(philo, "is eating\n", philo->table->start, philo->id);
	philo->n_eating++;
	usleep(philo->table->time_to_eat * 1000);
	philo->last_eat = take_time();
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->r_fork);
	if (sleeping(philo) == 1)
		return (1);
	return (0);
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