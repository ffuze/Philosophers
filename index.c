#include "./philo.h"
#include <sys/time.h>

pthread_mutex_t	*forks;
pthread_mutex_t	print_mutex;

long	get_time_ms(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	safe_print(char *msg, int philo_id, long timestamp)
{
	pthread_mutex_lock(&print_mutex);
	ft_printf("%ld %d %s\n", timestamp, philo_id, msg);
	pthread_mutex_unlock(&print_mutex);
}

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

void*    philosopher_routine(void* arg)
{
	t_philo *philo;
	long	current_time;

	philo = (t_philo*)arg;
	philo->last_meal_time = get_time_ms();
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		current_time = get_time_ms();
		safe_print("has taken a fork", philo->id, current_time);
		pthread_mutex_lock(philo->right_fork);
		current_time = get_time_ms();
		safe_print("has taken a fork", philo->id, current_time);
		current_time = get_time_ms();
		safe_print("is eating", philo->id, current_time);
		philo->last_meal_time = current_time;
		philo->meals_eaten++;
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		current_time = get_time_ms();
		safe_print("is sleeping", philo->id, current_time);
		usleep(philo->time_to_sleep * 1000);
		current_time = get_time_ms();
		safe_print("is thinking", philo->id, current_time);
		if (philo->must_eat_count != -1 && philo->meals_eaten >= philo->must_eat_count)
			break;
	}
	return (NULL);
}

void    create_philos(t_philo *philos, char **argv, int num_philos)
{
	int i;
	pthread_t   threads[num_philos];

	i = 0;
	if (!argv || !argv[1])
		return ;
	pthread_mutex_init(&print_mutex, NULL);
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
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % num_philos];
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_create(&threads[i], NULL, philosopher_routine, &philos[i]);
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
	pthread_mutex_destroy(&print_mutex);
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
void	init_philosophers(t_philo *philos, char **argv, int num_philos)
{
	int i;
	
	i = 0;
	(void)argv;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		// philos[i].time_to_die = ft_atoi(argv[2]);
		// philos[i].time_to_eat = ft_atoi(argv[3]);
		// philos[i].time_to_sleep = ft_atoi(argv[4]);
		// if (argv[5])
			// philos[i].must_eat_count = ft_atoi(argv[5]);
		// else
		// 	philos[i].must_eat_count = -1; // infinite
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_philo	*philos;
	int		num_philos;

	if (argc < 2/*argc < 5 || argc > 6*/)
		return (ft_printf("Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [must_eat_count]\n"));
	
	num_philos = ft_atoi(argv[1]);
	if (num_philos <= 0)
		return (ft_printf("!!!invalid number of philosophers!!!\n"));
		
	philos = malloc(sizeof(t_philo) * num_philos);
	if (!philos)
		return (ft_printf("!!!memory allocation failed!!!\n"));
	init_philosophers(philos, argv, num_philos);
	
	// Crea e gestisce i filosofi
	create_philos(philos, argv, num_philos);	
	
	free(philos);
	return 0;
}