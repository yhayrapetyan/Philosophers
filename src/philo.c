#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (check_input(ac, av) != 0)
		return (print_instructions());
	init_data(&data, ac, av);
	init_philos(&data);
	init_forks(&data);
	return (0);
}