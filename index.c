#include "./philo.h"

pthread_mutex_t	*forks;

// // the initial balance is 0
// int balance = 0;

// // write the new balance (after as simulated 1/4 second delay)
// void write_balance(int new_balance)
// {
//   usleep(500000);
//   balance = new_balance;
// }

// // returns the balance (after a simulated 1/4 seond delay)
// int read_balance()
// {
//   usleep(500000);
//   return balance;
// }

// // carry out a deposit
// void* deposit(void *amount)
// {
//   int account_balance = read_balance();
//   account_balance += *((int *) amount);
//   write_balance(account_balance);
//   return NULL;
// }

void	philo_sleeping(int	ttd, int tte, int tts, int pheat)
{
	ft_printf("%d is sleeping\n", philo->id);
}

void*    philosopher_routine(void* arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	pthread_mutex_lock(philo->right_fork);
	ft_printf("%d has taken a fork\n", philo->id);
	ft_printf("%d is eating\n", philo->id);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	ft_printf("%d is sleeping\n", philo->id);
	usleep(1000000);
	return (NULL);
}

void    create_philos(t_philo *philos, char **argv, int num_philos)
{
	int i;
	pthread_t   threads[num_philos];

	i = 0;
	if (!argv || !argv[1])
		return ;
	forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % num_philos];
		philos[i].meals_eaten = 0;
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_create(&threads[i], NULL, philosopher_routine, &philos[i]);
		usleep(ft_atoi(argv[2]) * 250000);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

// void	philos_loop(int	ttd, int tte, int tts, int pheat)
// {
// 	if (!ttd | !tte | !tts)
// 		return ;
// 	else if (!pheat)
// 		(void)pheat;
	
// }

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
*/
int main(int argc, char **argv)
{
	t_philo	*philos;
	int		num_philos;
	int		i;

	// make a while that puts for each philo their respective info (time to die, to sleep etc)

	(void)argc;
	i = 0;
	if (argc < 2)
		return (ft_printf("Insert the needed arguments to proceed\n"));
	num_philos = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * num_philos);
	if (!philos)
		return (ft_printf("Memory allocation failed\n"));
	create_philos(philos, argv, num_philos);	
	free(philos);
	return 0;
}