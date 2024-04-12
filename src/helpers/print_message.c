#include "philo.h"

void	print_message(t_data *data, int id, char *message)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
//	pthread_mutex_lock(&data->mut_print);
//	if (get_keep_iter(data))
	printf("%lu %d %s\n", time, id, message);
//	pthread_mutex_unlock(&data->mut_print);
}