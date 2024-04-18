#include "philo.h"

void		print_message(t_data *data, int id, char *message)
{
	uint64_t	time;
	int 		can_prt;

	time = get_time() - get_start_time(data);
	can_prt = can_print(data);
	pthread_mutex_lock(&data->mut_print);
	if (can_prt == 1 && get_philo_state(&data->philos[id - 1]) != DEAD)
		printf("%lu %d %s\n", time, id, message);
	pthread_mutex_unlock(&data->mut_print);
}