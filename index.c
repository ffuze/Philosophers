#include "./philo.h"

size_t	get_time_ms(void)
{
	struct timeval	time;
	
	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_info(char *msg, int philo_id, long timestamp, pthread_mutex_t *print_mutex)
{
	if (!print_mutex || !msg)
	{
		ft_printf("+++++++++++++++++++++++++++++++++++++++++++\n");
		return ;
	}
	pthread_mutex_lock(print_mutex);
	printf("-%ld- --%d-- ---%s---\n", timestamp, philo_id, msg);
	pthread_mutex_unlock(print_mutex);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < milliseconds)
		usleep(500);
	return (0);
}

// // the initial balance is 0
// int balance = 0;

// // write the new balance (after a 1/4 second delay)
// void write_balance(int new_balance)
// {
//   usleep(500000);
//   balance = new_balance;
// }

// // returns the balance (after a 1/4 seond delay)
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
		print_info("has taken a fork", philo->id, current_time, philo->print_mutex);
		pthread_mutex_lock(philo->right_fork);
		current_time = get_time_ms();
		print_info("has taken a fork", philo->id, current_time, philo->print_mutex);
		current_time = get_time_ms();
		print_info("is eating", philo->id, current_time, philo->print_mutex);
		philo->last_meal_time = current_time;
		philo->meals_eaten++;
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		current_time = get_time_ms();
		print_info("is sleeping", philo->id, current_time, philo->print_mutex);
		ft_usleep(philo->time_to_sleep);
		current_time = get_time_ms();
		print_info("is thinking", philo->id, current_time, philo->print_mutex);
		if (philo->must_eat_count != -1 && philo->meals_eaten >= philo->must_eat_count)
			break;
	}
	return (NULL);
}

void    create_philos(t_philo *philos, char **argv, int num_philos)
{
	int			i;
	pthread_t   threads[num_philos];
	t_misc		data;

	if (!argv || !argv[1])
		return ;
	pthread_mutex_init(&data.print_mutex, NULL);
	data.forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if (!data.forks)
		return;
	data.num_philos = num_philos;
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&data.forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		philos[i].left_fork = &data.forks[i];
		philos[i].right_fork = &data.forks[(i + 1) % num_philos];
		philos[i].print_mutex = &data.print_mutex;
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
		pthread_mutex_destroy(&data.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data.print_mutex);
	free(data.forks);
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
void	init_philosophers(t_philo *philos, char **argv, int argc, int num_philos)
{
	int i;
	
	i = 0;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		if (argc >= 3)
			philos[i].time_to_die = ft_atoi(argv[2]);
		else
			philos[i].time_to_die = 800;
		if (argc >= 4)
			philos[i].time_to_eat = ft_atoi(argv[3]);
		else
			philos[i].time_to_eat = 200;
		if (argc >= 5)
			philos[i].time_to_sleep = ft_atoi(argv[4]);
		else
			philos[i].time_to_sleep = 200;
		if (argc >= 6)
			philos[i].must_eat_count = ft_atoi(argv[5]);
		else
			philos[i].must_eat_count = -1; // infinite
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = 0;
		i++;
	}
}

static void	init_p_params(t_philo *philo)
{
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->print_mutex = NULL;
	philo->id = 0;
	philo->time_to_die = 0;
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->must_eat_count = 0;
	philo->time_to_sleep = 0;
	philo->time_to_eat = 0;
}

int main(int argc, char **argv)
{
	t_philo	*philos;
	int		num_philos;

	if (argc < 2)
		return (ft_printf("Usage: ./philo num_philos time_to_die time_to_eat time_to_sleep [must_eat_count]\n"));
	num_philos = ft_atoi(argv[1]);
	if (num_philos <= 0)
		return (ft_printf("!!!invalid number of philosophers!!!\n"));
	philos = malloc(sizeof(t_philo) * num_philos);
	if (!philos)
		return (ft_printf("!!!memory allocation failed!!!\n"));
	init_p_params(philos);
	init_philosophers(philos, argv, argc, num_philos);
	create_philos(philos, argv, num_philos);
	free(philos);
	return 0;
}