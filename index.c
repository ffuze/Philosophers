#include "./philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (printf("Invalid arguments\n"), 1);
	if (!take_args(&table, argv))
		return (printf("Error\n"), 1);
	init(&table);
	return (0);
}