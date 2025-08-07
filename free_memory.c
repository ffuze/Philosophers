#include "./philo.h"

void	free_philo(t_philo **philos)
{
	int	i;
	int	philo;

	philo = philos[0]->table->n_philo;
	i = -1;
	pthread_mutex_destroy(philos[0]->table->printing);
	pthread_mutex_destroy(philos[0]->table->simulation);
	free(philos[0]->table->printing);
	free(philos[0]->table->simulation);
	while (++i < philo)
	{
		pthread_mutex_destroy(philos[i]->fork);
		free(philos[i]->fork);
		free(philos[i]);
	}
	free(philos);
}