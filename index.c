#include "./philo.h"

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

void*    say_hi(void* id)
{
	ft_printf("%d: hey esisto anch'io!!!\n", (int)(long)id);
	return (NULL);
}

void    create_philos(t_philo *philos, char **argv)
{
	int i;
	pthread_t   threads[ft_atoi(argv[1])];
	int         num_philos;

	i = 0;
	num_philos = ft_atoi(argv[1]);
	if (!argv || !argv[1])
		return ;
	while (i < num_philos)
	{
		pthread_create(&threads[i], NULL, say_hi, (void*)(long)(i + 1));
		philos[i].id = i + 1;
		i++;
	}
	i = 0;
	while (i < num_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

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
	t_philo *philos;
	int num_philos;
	
	if (argc < 2)
		return (ft_printf("Insert the needed arguments to proceed\n"));
	
	num_philos = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * num_philos);
	if (!philos)
		return (ft_printf("Memory allocation failed\n"));
	
	create_philos(philos, argv);
	
	free(philos);
	return 0;
}