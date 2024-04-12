#include "philo.h"

void		print_message(t_data *data, int id, char *message)
{
	uint64_t	time;

	time = get_time() - data->start_time;
	pthread_mutex_lock(&data->mut_iteration);
	if (data->can_print == 1 && data->philos[id - 1].state != DEAD)
		printf("%lu %d %s\n", time, id, message);
	pthread_mutex_unlock(&data->mut_iteration);
}